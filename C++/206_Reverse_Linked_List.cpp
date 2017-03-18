
// TODO
// Linked List

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *pre = head;
        ListNode *p = head->next;
        head->next = NULL;
        while(p != NULL) {
            ListNode *nxt = p->next;
            p->next = pre;
            pre = p;
            p = nxt;
        }
        return pre;
    }
};


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head
        nxt = head.next
        head.next = None
        newHead = self.reverseList(nxt)
        nxt.next = head
        return newHead

