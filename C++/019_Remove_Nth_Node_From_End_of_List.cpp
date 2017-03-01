// https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL)
        {
            return NULL;    
        }
        
        ListNode *fast = head;
        for(int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }
        
        if(fast == NULL)
        {
            ListNode *tmp = head;
            head = head->next;    
            delete tmp;
            return head;
        }
        
        ListNode *slow = head;
        
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return head;
    }
};


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL)
        {
            return NULL;    
        }
        
        ListNode *fast = head;
        for(int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }
        
        if(fast == NULL)
        {
            return head->next;    
        }
        
        ListNode *slow = head;
        
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *fast = head;
    	ListNode *slow = head;

    	for(int i = 0; i < n; ++i)
    	{
    		fast = fast->next;
    	}

    	if(fast != NULL)
    	{
        	while(fast->next != NULL)
        	{
        	    fast = fast->next;
        	    slow = slow->next;
        	}

        	ListNode *tmp = slow->next;
        	slow->next = tmp->next;
        	delete tmp;

        	return head;
    	}
    	else
    	{
    		ListNode *tmp = head;
    		head = head->next;
    		delete tmp;

    		return head;
    	}
    }
};

