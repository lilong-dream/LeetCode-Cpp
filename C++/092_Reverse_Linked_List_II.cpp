
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *pre = NULL;
		ListNode *cur = head;
		if(m > 1) {
			pre = head;
			for(int i = 1; i < m - 1; ++i)
			{
				pre = pre->next;
			}
			cur = pre->next;
		}
		
		ListNode *rPre = pre;
		ListNode *rTail = cur;
		for(int i = m; i <= n; ++i) {
			ListNode *next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		if(m == 1) {
			rTail->next = cur;
			return pre;
		} else {
			rPre->next = pre;
			rTail->next = cur;
		
			return head;
		}
    }
};

