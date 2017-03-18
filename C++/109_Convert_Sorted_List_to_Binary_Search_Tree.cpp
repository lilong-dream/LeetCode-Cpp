
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *node;

    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL)
			return NULL;
			
		ListNode *n = head;
		int len = 0;
		while(n != NULL)
		{
			len++;
			n = n -> next;
		}
		
		node = head;
		return listToBST(0, len - 1);
    }
	
	TreeNode* listToBST(int start, int end)
	{
		if(start > end)
			return NULL;
			
		int mid = start + (end - start) / 2;

		TreeNode *left = listToBST(start, mid - 1);

		TreeNode *parent = new TreeNode(node->val);

		parent->left = left;

		node = node->next;  //

		parent->right = listToBST(mid + 1, end);
		
		return parent;
    }
};

