// https://oj.leetcode.com/problems/binary-tree-postorder-traversal/

// TODO
// Hard

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        
        if(root == NULL) {
            return res;
        }
        
        res = postorderTraversal(root->left);
        
        vector<int> right = postorderTraversal(root->right);
        
        res.insert(res.end(), right.begin(), right.end());
        
        res.push_back(root->val);
        
        return res;
    }
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        
        TreeNode *p = root, *q = NULL;
        
        std::stack<TreeNode*> st;
        
        do {
            while(p != NULL) {
                st.push(p);
                p = p->left;
            }
            q = NULL;
            while(!st.empty()) {
                p = st.top();
                st.pop();
                if(p->right == q) {  //
                    res.push_back(p->val);
                    q = p;
                } else {
                    st.push(p);
                    p = p -> right;
                    break;
                }
            }
        } while(!st.empty());
        
        return res;
    }
};

