
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
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode *left = sortList(head);
        ListNode *right = sortList(fast);
        return merge(left, right);
    }
    
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode dummy(-1);
        ListNode *node = &dummy;
        while(left || right) {
            int lval = left ? left->val : INT_MAX;
            int rval = right ? right->val : INT_MAX;
            if(lval < rval) {
                node->next = left;
                left = left->next;
            } else {
                node->next = right;
                right = right->next;
            }
            node = node->next;
        }
        return dummy.next;
    }
};


class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
		{
			return head;
		}

		ListNode *slow = head;
		ListNode *fast = head;
		while(fast->next)
		{
			fast = fast->next->next;
			if(fast == NULL)
			{
				break;
			}	
			slow = slow->next;
		}

		ListNode *h2 = slow->next;
		slow->next = NULL;
		ListNode *h1 = sortList(head);
		h2 = sortList(h2);
		ListNode *res = mergeTwoSortedList(h1, h2);
		return res;
    }

	ListNode *mergeTwoSortedList(ListNode *h1, ListNode *h2)
	{
		if(h1 == NULL)
		{
			return h2;
		}
		if(h2 == NULL)
		{
			return h1;
		}
		ListNode *res = NULL;
		ListNode *cur = NULL;
		while(h1 || h2)
		{
			if(h1 && h2)
			{
				if(h1->val < h2->val)
				{
					if(res == NULL)
					{
						res = h1;
						cur = res;
					}
					else
					{
						cur->next = h1;
						cur = cur->next;
					}
					h1 = h1->next;
				}
				else
				{
					if(res == NULL)
					{
						res = h2;
						cur = res;
					}
					else
					{
						cur->next = h2;
						cur = cur->next; // !
					}	
					h2 = h2->next;
				}
			}
			else if(h1)
			{
				while(h1)
				{
					cur->next = h1; // !
					cur = cur->next;
					h1 = h1->next;
				}
			}
			else
			{
				while(h2)
				{
					cur->next = h2; 
					cur = cur->next;
					h2 = h2->next;
				}
			}
		}

		cur->next = NULL;  // end with null

		return res;
    }
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
		if(head == NULL || head->next == NULL)
		{
			return head;
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
		}

		ListNode *right = slow->next;
		slow->next = NULL;

		ListNode *left = sortList(head);
		right = sortList(right);

		return mergeTwoLists(left, right);
	}

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

