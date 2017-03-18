
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> cur;
        if(n < k) {
            return res;
        }
        dfs(n, k, 1, cur, res);
        return res;
    }
    
    void dfs(int n, int k, int start, vector<int> &cur, vector<vector<int> > &res) {
        if(cur.size() == k) {
            res.push_back(cur);
            return;
        }
        
        for(int i = start; i <= n; ++i) {
            cur.push_back(i);
            dfs(n, k, i + 1, cur, res);
            cur.pop_back();
        }
    }
};

