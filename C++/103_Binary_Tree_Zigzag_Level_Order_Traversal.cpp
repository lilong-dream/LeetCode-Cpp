
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        int flag = 1;
        while(!que.empty()) {
            int size = que.size();
            vector<int> cur;
            
            while(size--) {
                TreeNode* node = que.front();
                que.pop();
				// int index = (leftToRight) ? i : (size - 1 - i);  // this is better
                if(flag == 1) {
                    cur.push_back(node->val);
                } else {
                    cur.insert(cur.begin(), node->val);  //
                }
                if(node->left) {
                    que.push(node->left);
                }
                if(node->right) {
                    que.push(node->right);
                }
            }
            res.push_back(cur);
            flag = -flag;
        }
        return res;
    }
};

