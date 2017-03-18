
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) {
			return;
		}

		std::queue<TreeLinkNode*> q;
		q.push(root);
		q.push(NULL);

		while(!q.empty()) {
			TreeLinkNode * node = q.front();
			q.pop();
			
			if(node == NULL) {
				if(!q.empty()) {
					q.push(NULL);
				}
				continue;
			}

			node->next = q.front();

			if(node->left) {
				q.push(node->left);
			}
			if(node->right) {
				q.push(node->right);
			}
		}
    }
};

