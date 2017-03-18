
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
    void flatten(TreeNode *root) {
        if(root == NULL) {
			return;
		}

		std::stack<TreeNode*> s;  //
		s.push(root);

		while(!s.empty()) {
			TreeNode *node = s.top();
			s.pop();
			if(node->right) {
				s.push(node->right);
			}
			if(node->left) {
				s.push(node->left);
			}
			node->left = NULL;
			if(!s.empty()) {
				node->right = s.top();
			}
		}
    }
};

