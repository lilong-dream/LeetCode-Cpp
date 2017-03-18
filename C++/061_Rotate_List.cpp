
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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || k == 0) {
    		return head;
    	}

    	int length = 1;
    	ListNode *node = head;
    	while(node->next != NULL) {
    		++length;
    		node = node->next;
    	}

    	node->next = head;

    	int m = k % length;

    	for(int i = 0; i < length - m; ++i) {
    		node = node->next;
    	}

    	head = node->next;

    	node->next = NULL;

    	return head;
    }
};

