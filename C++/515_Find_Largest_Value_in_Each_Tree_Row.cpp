
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int cur = 0;
            int last = que.size();
            int max = INT_MIN;
            while(cur < last) {
                TreeNode* node = que.front();
                que.pop();
                if(node->val > max) {
                    max = node->val;
                }
                if(node->left) {
                    que.push(node->left);
                }
                if(node->right) {
                    que.push(node->right);
                }
                cur++;
            }
            res.push_back(max);
        }
        return res;
    }
};

