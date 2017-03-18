// https://oj.leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                slow = head;
                while(slow != fast) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast->next != NULL)
        {
            fast = fast->next->next;
            
            if(fast == NULL)
            {
                break;
            }
            
            slow = slow->next;
            
            if(fast == slow)
            {
                slow = head;
                
                while(fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                
                return slow;
            }
        }
        
        return NULL;
    }
};

