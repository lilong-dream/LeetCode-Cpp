
// TODO

// http://www.jiuzhang.com/solutions/inorder-successor-in-bst/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        TreeNode successor = null;
        while (root != null && root.val != p.val) {
            if (root.val > p.val) {
                successor = root;
                root = root.left;
            } else {
                root = root.right;
            }
        }
        
        if (root == null) {
            return null;
        }
        
        if (root.right == null) {
            return successor;
        }
        
        root = root.right;
        while (root.left != null) {
            root = root.left;
        }
        
        return root;
    }
}


// https://segmentfault.com/a/1190000007339719

public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
    if(root == null) {
		return null;
	}
    TreeNode res = null;
    while(root != null) {
        // 如果是小于等于的值，就要往右移动
        if(root.val <= p.val) {
            root = root.right;
        }
        // 比root大的值都可能是successor，所以要保留
        else {
            res = root;
            root = root.left;
        }
    }
    return res;
}

