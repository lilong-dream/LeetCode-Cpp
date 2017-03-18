
// Hard

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct compare {
    bool operator() (ListNode* &left, ListNode* &right){
        return left->val > right->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode * head = NULL;
        ListNode * tail = NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare> heap;
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i] != NULL){
                heap.push(lists[i]);  // head of each list
            }
        }

        while(!heap.empty()){
            ListNode * current = heap.top(); 
            heap.pop();
            if(head == NULL){
                head = current;
                tail = current;
            }
            else{
                tail->next = current;
                tail = tail->next;
            }
            if(current->next != NULL){
                heap.push(current->next);
            }
        }
		
        return head;
    }
};

