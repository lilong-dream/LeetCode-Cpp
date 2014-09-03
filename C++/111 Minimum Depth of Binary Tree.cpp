// https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode *root) {
        if(root == NULL)
        {
            return 0;
        }
        
        int res = 1;
        
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            
            if(node == NULL)
            {
                ++res;
                q.push(NULL);
                continue;
            }
            
            if(node->left == NULL && node->right == NULL)
            {
                break;
            }
            if(node->left != NULL)
            {
                q.push(node->left);
            }
            if(node->right != NULL)
            {
                q.push(node->right);
            }
        }
        
        return res;
    }
};
