
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) {
			return NULL;
		}
		
		RandomListNode *cur = head;
		while(cur != NULL) {
			RandomListNode *cpy = new RandomListNode(cur->label);
			cpy->next = cur->next;
			cur->next = cpy;
			cur = cpy->next;
		}
		
		cur = head;
		while(cur != NULL) {
			if(cur->random != NULL) {
				cur->next->random = cur->random->next;
			}
			cur = cur->next->next;
		}
		
		cur = head;
		RandomListNode *newHead = head->next;
		while(cur != NULL) {
			RandomListNode *cpyNext = cur->next;
			cur->next = cpyNext->next;
			if(cpyNext->next != NULL) {
				cpyNext->next = cpyNext->next->next;
			}
			cur = cur->next;
		}
		
    	return newHead;
    }
};

