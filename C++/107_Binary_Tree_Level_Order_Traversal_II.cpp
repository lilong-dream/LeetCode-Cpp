
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> vec;
        queue<TreeNode*> que;
        while(!q.empty()) {
            TreeNode* n = q.front();
            q.pop();
            vec.push_back(n->val);
            if(n->left) {
                que.push(n->left);
            }
            if(n->right) {
                que.push(n->right);
            }
            if(q.empty()) {
                res.insert(res.begin(), vec);
                vec.clear();
                if(!que.empty()) {
                    swap(q, que);
                }
            }
        }
        return res;
    }
};

