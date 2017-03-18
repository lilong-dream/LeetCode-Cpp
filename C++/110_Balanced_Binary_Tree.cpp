// https://oj.leetcode.com/problems/balanced-binary-tree/

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
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return helper(root, depth);
    }
    
    bool helper(TreeNode *root, int &depth)
    {
        if(root == NULL)
        {
            depth = 0;
            return true;
        }
        
        int l, r;
        bool left = helper(root->left, l);
        bool right = helper(root->right, r);
        
        if(left && right && l - r >= -1 && l - r <= 1)
        {
            depth = std::max(l, r) + 1;
            return true;
        }
        
        return false;
    }
};

    
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
private:
    int check(TreeNode* root) {
       if (root == NULL) {
	       return 0;
	   }
       
       int lch = check(root -> left);
       int rch = check(root -> right);

       // 检查子树是否存在不平衡
       if (lch == -1 || rch == -1 || abs(lch - rch) > 1) {
	       return -1;
	   }
       
       // 返回当前子树高度
       return (lch > rch ? lch : rch) + 1;
    }

    int abs(int x) {
        return x > 0 ? x : -x;
    }
};

class Solution {
public:
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return std::max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        if(isBalanced(root->left) && isBalanced(root->right))
        {
            int left = height(root->left);
            int right = height(root->right);
            if(abs(left - right) <= 1) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root == NULL)
			return true;
		
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		
		if(std::abs(left - right) > 1)
			return false;
		
		return isBalanced(root->left) && isBalanced(root->right);
    }
	
	int getHeight(TreeNode *root)
	{
		if(root == NULL)
			return 0;
		
		return std::max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};

