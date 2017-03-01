
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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        
        if(root == NULL) {
            return res;
        }
        
        map<int, int> m;
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()) {
            TreeNode* q = que.front();
            que.pop();
            if(m.find(q->val) == m.end()) {
                m[q->val] == 1;
            } else {
                m[q->val]++;
            }
            if(q->left) {
                que.push(q->left);
            }
            if(q->right) {
                que.push(q->right);
            }
        }
        
        int max = INT_MIN;
        auto iter = m.begin();
        while(iter != m.end()) {
            if(iter->second > max) {
                max = iter->second;
            }   
            iter++;  //
        }
        
        iter = m.begin();
        while(iter != m.end()) {
            if(iter->second == max) {
                res.push_back(iter->first);
            }   
            iter++;  //
        }
        
        return res;
    }
};

