
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL) {
            return true;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        stack<ListNode*> st;
        ListNode* node = head;
        while(node != slow) {  // reverse is better
            st.push(node);
            node = node->next;
        }
        
        if(fast) {
            slow = slow->next;  // has odd nodes
        }
        
        while(!st.empty()) {
            ListNode *node = st.top();
            st.pop();
            if(node->val != slow->val) {
                return false;
            }
            slow = slow->next;
        }
        return true;
    }
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
		if(head == NULL) {
			return true;
		}

		ListNode* fast = head;
		ListNode* slow = head;

		while(fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}

		if(fast) {
			slow = slow->next;
		}

		ListNode *second = reverseList(slow);

		while(second) {
			if(second->val != head->val) {
				return false;
			}
			second = second->next;
			head = head->next;
		}
		
		return true;
    }

	ListNode *reverseList(ListNode* head) {
		if(head == NULL || head->next == NULL) {
			return head;
		}

		ListNode *pre = head;
		ListNode *p = head->next;
		head->next = NULL;
		while(p) {
			ListNode *nxt = p->next;
			p->next = pre;
			pre = p;
			p = nxt;
		}
		return pre;
	}
};

