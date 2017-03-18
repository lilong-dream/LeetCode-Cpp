// https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxPathSum(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }
        
        int max = INT_MIN;
        
        maxSum(root, max);
        
        return max;
    }
    
    int maxSum(TreeNode *node, int &max) {
        int left = 0, right = 0;
        if(node->left != NULL) {
            left = maxSum(node->left, max);
        }
        if(node->right != NULL) {
            right = maxSum(node->right, max);
        }
        if(left < 0) {
            left = 0;
        }
        if(right < 0) {
            right = 0;
        }
        
        max = std::max(max, node->val + left + right);
        
        return node->val + std::max(left, right);
    }
};


class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;  // !
        helper(root, maxSum);
        return maxSum;
    }
    
    int helper(TreeNode *root, int &crossSum) {
        if(root == NULL) {
            return 0;
        }
        int left = helper(root->left, crossSum);
        int right = helper(root->right, crossSum);
        if(left < 0) {
            left = 0;
        }
        if(right < 0) {
            right = 0;
        }
        crossSum = std::max(crossSum, left + root->val + right);
        return std::max(left, right) + root->val;
    }
};

