
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int inStart = 0;
		int inEnd = inorder.size() - 1;
		int postStart = 0;
		int postEnd = postorder.size() - 1;

		return buildTree(inorder, inStart, inEnd, postorder, postStart, postEnd);
    }

	TreeNode *buildTree(vector<int> &inorder, int inStart, int inEnd,
						vector<int> &postorder, int postStart, int postEnd) {
		if(inStart > inEnd || postStart > postEnd) {
			return NULL;
		}

		int rootValue = postorder[postEnd];
		TreeNode *root = new TreeNode(rootValue);

		int k = 0;
		for(int i = inStart; i <= inEnd; ++i) {
			if(inorder[i] == rootValue) {
				k = i;
				break;
			}
		}

		root->left = buildTree(inorder, inStart, k - 1, postorder, postStart, postStart + k - 1 - inStart);
		root->right = buildTree(inorder, k + 1, inEnd, postorder, postStart + k - inStart, postEnd - 1);

		return root;
    }
};

