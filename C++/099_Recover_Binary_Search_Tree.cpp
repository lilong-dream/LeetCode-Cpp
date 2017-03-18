
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
    TreeNode *pre, *p1, *p2;

	void run(TreeNode *root) {
		if(!root) { 
			return;
		}

		run(root->left);

		if(pre && pre->val > root->val) {
			if(p1 == NULL) {
				p1 = pre; 
			}

			p2 = root;
		}
		pre = root;

		run(root->right);
	}

	void recoverTree(TreeNode *root) {
		if(!root) {
			return;
		}
		pre = p1 = p2 = NULL;
		run(root);
		std::swap(p1->val, p2->val);
    }
};

