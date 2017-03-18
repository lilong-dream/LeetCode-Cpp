// Problem:  http://oj.leetcode.com/problems/validate-binary-search-tree/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/22780563
// 1988lilong@163.com

#include <iostream>
#include <limits.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
    	return isValidBST(root, INT_MIN, INT_MAX);
    }

    bool isValidBST(TreeNode *root, int min, int max) {
    	if(root == NULL) {
    		return true;
    	}

    	return 	root->val > min && root->val < max
    			&& isValidBST(root->left, min, root->val)
    			&& isValidBST(root->right, root->val, max);
    }
};

int main()
{
	TreeNode n1(2);
	TreeNode n2(1);
	TreeNode n3(3);
	n1.left = &n2;
	n1.right = &n3;

	Solution slt;
	std::cout << slt.isValidBST(&n1) << std::endl;
}

