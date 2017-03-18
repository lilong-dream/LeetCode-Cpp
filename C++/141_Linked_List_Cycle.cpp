// https://oj.leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return false;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                return true;
            }
        }

        return false;
    }
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return false;
        }
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast->next != NULL) {
            fast = fast->next->next;
            
            if(fast == NULL) {
                return false;
            }
            
            slow = slow->next;
            
            if(fast == slow) {
                return true;
            }
        }
        
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *slow = head;
        ListNode *quick = head->next;
        while(quick->next) {
            quick = quick->next->next;
            if(quick == NULL) {
                return false;
            }
            slow = slow->next;
            if(quick == slow) {
                return true;
            }
        }
        return false;
    }
};

