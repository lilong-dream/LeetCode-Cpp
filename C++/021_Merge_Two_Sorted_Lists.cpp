// https://oj.leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)
        {
            return l2;
        }
        if(l2 == NULL)
        {
            return l1;
        }
        
        ListNode *head = new ListNode(-1);  // !
        ListNode *l3 = head;
        
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }

            l3 = l3->next;
        }
        
        if(l1)
        {
            l3->next = l1;
        }
        else
        {
            l3->next = l2;
        }
        
        l3 = head->next;
        delete head;
        
        return l3;
    }
};


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if(l1 == NULL)
		{
			return l2;
		}
		if(l2 == NULL)
		{
			return l1;
		}

		ListNode *node = NULL;

		if(l1->val <= l2->val)
		{
			node = l1;
			l1 = l1->next;
		}
		else
		{
			node = l2;
			l2 = l2->next;
		}

		ListNode *head = node;

		while(l1 != NULL && l2 != NULL)
		{
			if(l1->val <= l2->val)
			{
				node->next = l1;
				node = node->next;

				l1 = l1->next;
			}
			else
			{
				node->next = l2;
				node = node->next;

				l2 = l2->next;
			}
		}

		if(l1 != NULL)
		{
			node->next = l1;
		}
		else if(l2 != NULL)
		{
			node->next = l2;
		}

		return head;
    }
};

