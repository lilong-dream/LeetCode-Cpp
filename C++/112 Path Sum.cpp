// https://oj.leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL)
        {
            return false;    
        }
        
        std::queue<TreeNode*> nodes;
        nodes.push(root);
        std::queue<int> values;
        values.push(root->val);
        
        while(!nodes.empty())
        {
            TreeNode *node = nodes.front();
            nodes.pop();
            int value = values.front();
            values.pop();
            
            if(node->left == NULL && node->right == NULL && value == sum)
            {
                return true;
            }
            
            if(node->left != NULL)
            {
                nodes.push(node->left);
                values.push(value + node->left->val);
            }
            
            if(node->right != NULL)
            {
                nodes.push(node->right);
                values.push(value + node->right->val);
            }
        }
        
        return false;
    }
};
