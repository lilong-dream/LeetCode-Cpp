// https://oj.leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        
        if(root == NULL) {
            return res;
        }
        
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        
        res.insert(res.end(), left.begin(), left.end());
        res.push_back(root->val);
        res.insert(res.end(), right.begin(), right.end());
        
        return res;
    }
    
    vector<int> inorderTraversalIter(TreeNode *root) {
        vector<int> res;

        std::stack<TreeNode*> s;
        
        TreeNode *p = root;
        
        while(!s.empty() || p != NULL) {
            if(p != NULL) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        
        return res;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
		helper(root, res);

		return res;
    }

	void helper(TreeNode *root, vector<int> &res) {
		if(root == NULL)
		{
			return;
		}
		helper(root->left, res);
		res.push_back(root->val);
		helper(root->right, res);
    }
};

