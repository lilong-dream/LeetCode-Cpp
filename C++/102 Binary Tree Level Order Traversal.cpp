// https://oj.leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        
        if(root == NULL)
        {
            return res;
        }
     
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> cur;
        
        while(!q.empty())
        {
            TreeNode *node = q.front();  // front not top
            q.pop();
            
            if(node == NULL)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                }
                res.push_back(cur);
                cur.clear();
                continue;
            }
            
            cur.push_back(node->val);
            
            if(node->left != NULL)
            {
                q.push(node->left);  // push not push_back
            }
            if(node->right != NULL)
            {
                q.push(node->right);
            }
        }
        
        return res;
    }
};
