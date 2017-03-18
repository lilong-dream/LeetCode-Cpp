// https://oj.leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)
        {
            return true;
        }
        
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode *left, TreeNode *right)
    {
        if(left == NULL && right == NULL)
        {
            return true;
        }
        if(left == NULL || right == NULL)
        {
            return false;
        }
        if(left->val != right->val)
        {
            return false;
        }
        
        return helper(left->left, right->right) && helper(left->right, right->left);
    }
};


class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) {
			return true;
		}
		
		std::queue<TreeNode*> q1;
		std::queue<TreeNode*> q2;
		q1.push(root->left);
		q2.push(root->right);
		
		while(!q1.empty() && !q2.empty()) {
			TreeNode *left = q1.front();
			q1.pop();
			TreeNode *right = q2.front();
			q2.pop();
			
			if(left == NULL && right != NULL || left != NULL && right == NULL) {
				return false;
			}
			
			if(left != NULL && right != NULL) {
				if(left->val != right->val)
					return false;
				
				q1.push(left->left);
				q2.push(right->right);
				
				q1.push(left->right);
				q2.push(right->left);
			}
		}
		
		return true;
    }
};

