
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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode dummy(INT_MIN);
        
        while(head) {
            ListNode *node = &dummy;
            ListNode *pre = node;
            while(node && node->val <= head->val) {  // !
                pre = node;
                node = node->next;
            }
            pre->next = head;
            head = head->next;
            pre->next->next = node;
        }
        return dummy.next;
    }
};


class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
		{
			return head;
		}
		
		ListNode *dummy = new ListNode(0);
		dummy->next = head;

		ListNode *pre = head;
		ListNode *cur = head->next;

		while(cur)
		{
			if(cur->val >= pre->val)
			{
				cur = cur->next;
				pre = pre->next;
				continue;
			}

			ListNode *pos = dummy;
			while(pos->next->val < cur->val)
			{
				pos = pos->next;
			}

			pre->next = cur->next;

			ListNode *post = pos->next;
			pos->next = cur;
			cur->next = post;

			cur = pre->next;
		}

		return dummy->next;
    }
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
		if (!head || !head->next) return head;
		ListNode *fakeHead = new ListNode(0);
		fakeHead->next = head;
		ListNode *iterate = head;
		while (iterate->next) {
			ListNode *next = iterate->next;
			if (next->val >= iterate->val) {
				iterate = iterate->next;
				continue;
			}
			ListNode *pos = fakeHead;
			while(pos->next->val < next->val) {
				pos = pos->next;
			}
			iterate->next = next->next;
			next->next=pos->next;
			pos->next = next;
		}
		return fakeHead->next;
	}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
		if(head == NULL || head->next == NULL)
		{
			return head;
		}

		ListNode *node = head;
		ListNode *cur = NULL;

		while(node->next != NULL)
		{
			cur = node->next;

			if(cur->val >= node->val)
			{
				node = node->next;
				continue;
			}

			node->next = cur->next;

			if(cur->val <= head->val)
			{
				cur->next = head;
				head = cur;
				continue;
			}

			ListNode *pos = findInsertPos(head, cur);

			cur->next = pos->next;
			pos->next = cur;
		}

		return head;
	}

	ListNode *findInsertPos(ListNode *head, ListNode *node)
	{
		ListNode *pos = head;
		while(head != NULL && head->val < node->val)
		{
			pos = head;
			head = head->next;
		}

		return pos;
	}
};

