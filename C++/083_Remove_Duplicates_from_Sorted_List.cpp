
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *pre = head;
        ListNode *cur = pre->next;
        while(cur) {
            if(cur->val == pre->val) {
                cur = cur->next;
                pre->next = cur;
            } else {
                cur = cur->next;
                pre = pre->next;
            }
        }
        return head;
    }
};


class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) return nullptr;
		for (ListNode *prev = head, *cur = head->next; cur; cur = cur->next) {
			if (prev->val == cur->val) {
				prev->next = cur->next;
				delete cur;  //
			} else {
				prev = cur;
			}
		}
		return head;
    }
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
    	if(head == NULL || head->next == NULL)
    	{
    		return head;
    	}

    	ListNode *pre = head;
    	ListNode *cur = head->next;

    	while(cur != NULL)
    	{
    		if(cur->val != pre->val)
    		{
    			pre = cur;
    			cur = cur->next;
    			continue;
    		}

    		while(cur->next != NULL && cur->next->val == pre->val)
    		{
    			cur = cur->next;
    		}

    		pre->next = cur->next;
    		cur = pre->next;
    	}

    	return head;
    }
};

