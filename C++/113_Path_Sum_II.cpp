
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> cur;
        helper(root, sum, cur, res);
        return res;
    }
    
    void helper(TreeNode *root, int gap, vector<int> &cur, vector<vector<int> > &res) {
        if(root == NULL) {
            return;
        }
        
        cur.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL && root->val == gap) {
             res.push_back(cur);  // not return! should pop
             cur.pop_back();
             return;
        }
        
        helper(root->left, gap - root->val, cur, res);
        helper(root->right, gap - root->val, cur, res);
        
        cur.pop_back();
    }
};

