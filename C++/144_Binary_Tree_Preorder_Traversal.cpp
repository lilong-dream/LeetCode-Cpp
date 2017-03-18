// https://oj.leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        
        if(root == NULL) {
            return res;
        }
        
        res.push_back(root->val);
        
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        
        return res;
    }
    
    vector<int> preorderTraversalIter(TreeNode *root) {
        vector<int> res;
        
        if(root == NULL) {
            return res;
        }
        
        std::stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            
            res.push_back(node->val);
            
            if(node->right != NULL) {  // not root!!
                st.push(node->right);
            }
            
            if(node->left != NULL) {
                st.push(node->left);
            }
        }
        
        return res;
    }
};

