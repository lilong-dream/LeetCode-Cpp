// https://oj.leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        
        if(root == NULL)
        {
            return res;
        }
        
        res = postorderTraversal(root->left);
        
        vector<int> right = postorderTraversal(root->right);
        
        res.insert(res.end(), right.begin(), right.end());
        
        res.push_back(root->val);
        
        return res;
    }
};
