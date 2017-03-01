// https://oj.leetcode.com/problems/add-two-numbers/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)
        {
            return l2;
        }
        if(l2 == NULL)
        {
            return l1;
        }
        
        ListNode *head = NULL;
        ListNode *node = NULL;
        
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL)
        {
            int res = carry;
            if(l1 != NULL)
            {
                res += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                res += l2->val;
                l2 = l2->next;
            }
            
            if(res >= 10)
            {
                carry = 1;
                res -= 10;
            }
            else
            {
                carry = 0;  // ! 
            }
            
            ListNode *n = new ListNode(res);
            
            if(head == NULL)
            {
                head = n;
                node = head;
            }
            else
            {
                node->next = n;
                node = node->next;
            }
        }
        
        if(carry == 1)
        {
            node->next = new ListNode(1);
        }
        
        return head;
    }
};

