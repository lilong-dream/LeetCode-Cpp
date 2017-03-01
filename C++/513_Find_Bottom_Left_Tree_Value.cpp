
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
    int findBottomLeftValue(TreeNode* root) {
        int res = 0;
        
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int cur = 0;
            int last = que.size();
            int flag = 0;
            int res = que.front()->val;
            while(cur < last) {
                TreeNode* n = que.front();
                que.pop();
                
                if(n->left) {
                    flag = 1;
                    que.push(n->left);
                }
                if(n->right) {
                    flag = 1;
                    que.push(n->right);
                }
                
                cur++;
            }
            if(flag == 0) {
                return res;
            }
        }
        
        return res;
    }
};

