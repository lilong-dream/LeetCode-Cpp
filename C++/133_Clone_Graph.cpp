
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) {
			return NULL;
		}
		
		std::queue<UndirectedGraphNode*> q;
		map<UndirectedGraphNode*, UndirectedGraphNode*> m;
		
		UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
		
		q.push(node);
		m[node] = newNode;
		
		while(!q.empty()) {
			UndirectedGraphNode* cur = q.front();
			q.pop();
			
			for(UndirectedGraphNode* neighbor : cur->neighbors) {
				if(m.find(neighbor) != m.end()) {
					m[cur]->neighbors.push_back(m[neighbor]);
				} else {
					UndirectedGraphNode* cpy = new UndirectedGraphNode(neighbor->label);
					m[cur]->neighbors.push_back(cpy);
					q.push(neighbor);
					m[neighbor] = cpy;
				}
			}
		}
		
		return newNode;
    }
};

