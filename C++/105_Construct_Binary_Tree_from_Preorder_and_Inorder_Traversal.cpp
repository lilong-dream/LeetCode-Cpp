
// TODO
// Tree

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty() || preorder.size() != inorder.size()) {
            return NULL;
        }
        
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode *buildTree(vector<int> &preorder, int preBegin, int preEnd, 
                        vector<int> &inorder, int inBegin, int inEnd) {
        if(preBegin > preEnd) {
            return NULL;            
        }
        
        TreeNode* root = new TreeNode(preorder[preBegin]);  // not 0
        
        int seperator = inBegin;  //
        while(seperator <= inEnd) {
            if(inorder[seperator] == root->val) {
                break;
            } else {
                ++seperator;
            }
        }
        
        root->left = buildTree(preorder, preBegin + 1, preBegin + seperator - inBegin, 
                                   inorder, inBegin, seperator - 1);
        root->right = buildTree(preorder, preBegin + seperator - inBegin + 1, preEnd, 
                                   inorder, seperator + 1, inEnd);
        
        return root;
    }
};


class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int preStart = 0;
		int preEnd = preorder.size() - 1;
		int inStart = 0;
		int inEnd = inorder.size() - 1;

		return buildTree(preorder, preStart, preEnd, inorder, inStart, inEnd);
    }

	TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd, 
						vector<int> &inorder, int inStart, int inEnd) {
		if(preStart > preEnd || inStart > inEnd) {
			return NULL;
		}

		int rootValue = preorder[preStart];
		TreeNode *root = new TreeNode(rootValue);

		int k = 0;
		for(int i = inStart; i <= inEnd; ++i) {
			if(inorder[i] == rootValue) {
				k = i;
				break;
			}
		}

		root->left = buildTree(preorder, preStart + 1, preStart + k - inStart, inorder, inStart, k - 1);
		root->right = buildTree(preorder, preStart + k - inStart + 1, preEnd, inorder, k + 1, inEnd);
		
		return root;
    }
};

