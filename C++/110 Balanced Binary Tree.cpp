// https://oj.leetcode.com/problems/balanced-binary-tree/

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
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return helper(root, depth);
    }
    
    bool helper(TreeNode *root, int &depth)
    {
        if(root == NULL)
        {
            depth = 0;
            return true;
        }
        
        int l, r;
        bool left = helper(root->left, l);
        bool right = helper(root->right, r);
        
        if(left && right && l - r >= -1 && l - r <= 1)
        {
            depth = std::max(l, r) + 1;
            return true;
        }
        
        return false;
    }
};
