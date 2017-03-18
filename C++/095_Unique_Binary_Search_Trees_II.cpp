
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
    vector<TreeNode*> generateTrees(int n) {
         return generateTrees(1, n);
    }
	
	vector<TreeNode*> generateTrees(int start, int end) {
		vector<TreeNode*> v;

		if(start > end) {
			v.push_back(NULL);
			return v;
		}

		for(int i = start; i <= end; ++i) {
			vector<TreeNode*> lefts = generateTrees(start, i - 1);
			vector<TreeNode*> rights = generateTrees(i + 1, end);
			for(TreeNode *left : lefts) {
				for(TreeNode *right : rights) {
					TreeNode *node = new TreeNode(i);
					node->left = left;
					node->right = right;
					v.push_back(node);
				}
			}
		}
		
		return v;
    }
};

