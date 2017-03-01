
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }
        int lenA = 1;
        ListNode *hA = headA;
        while(hA->next != NULL)
        {
            ++lenA;
            hA = hA->next;
        }
        
        int lenB = 1;
        ListNode *hB = headB;
        while(hB->next != NULL)
        {
            ++lenB;
            hB = hB->next;
        }
        
        if(hA != hB)
        {
            return NULL;
        }
        
        hA = headA;
        hB = headB;
        if(lenA > lenB)
        {
            for(int i = 0; i < lenA - lenB; ++i)
            {
                hA = hA->next;
            }
        }
        else
        {
            for(int i = 0; i < lenB - lenA; ++i)
            {
                hB = hB->next;
            }
        }
        while(hA != hB)
        {
            hA = hA->next;
            hB = hB->next;
        }
        return hA;
    }
};

