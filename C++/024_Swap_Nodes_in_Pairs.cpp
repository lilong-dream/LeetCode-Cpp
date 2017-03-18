
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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL) {
			return head;
		}
			
		ListNode *pre = head;
		ListNode *cur = head->next;
		ListNode *post = cur->next;
		
		head = cur;
		cur->next = pre;
		
		while(post != NULL && post->next != NULL)
		{
			cur = post->next;
			pre->next = cur;
			pre = post;
			post = cur->next;
			cur->next = pre;
		}
		
		if(post != NULL)
		{
			pre->next = post;
		}
		else
		{
			pre->next = NULL;
		}
		
    	return head;
    }
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *pre = NULL;
        ListNode *res = NULL;
        ListNode *cur = head;
        ListNode *nxt = head->next;
        while(nxt != NULL) {
            if(res == NULL) {
                res = nxt;
            } else {
                pre->next = nxt;
            }
            ListNode *tmp = nxt->next;
            nxt->next = cur;
            pre = cur;
            cur = tmp;
            if(tmp != NULL) {
                nxt = tmp->next;
            } else {
                pre->next = NULL;
                return res;
            }
        }
        pre->next = cur;
        cur->next = NULL;
        return res;
    }
};

