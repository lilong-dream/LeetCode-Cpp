
// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
// You must do this in-place without altering the nodes' values.
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

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
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL
            || head->next->next == NULL) {
            return;
        }
        
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        
        ListNode *right = reverse(fast);
        ListNode *left = head;
        
        while(left && right) {
            ListNode *rnext = right->next;
            right->next = left->next;
            left->next = right;
            left = right->next;
            right = rnext;
        }
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};


class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL)
		{
			return;
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
		ListNode *right = slow->next;
		slow->next = NULL;
		right = reverse(right);

		ListNode *left = head;

		ListNode *leftpost = NULL;
		ListNode *rightpost = NULL;
		while(right)
		{
			leftpost = left->next;
			rightpost = right->next;
			left->next = right;
			right->next = leftpost;
			left = leftpost;
			right = rightpost;
		}
		//if(left)
		//{
		//	left->next = NULL;
		//}
    }

	ListNode *reverse(ListNode *h)
	{
		if(h == NULL || h->next == NULL)
		{
			return h; 
		}
		ListNode *pre = h;
		ListNode *cur = h->next;
		ListNode *post = cur->next;
		cur->next = pre;
		pre->next = NULL;
		while(post)
		{
			pre = cur;
			cur = post;
			post = post->next;
			cur->next = pre;
		}
		h = cur; 
		return h;
    }
};

