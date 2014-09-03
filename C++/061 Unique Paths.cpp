// https://oj.leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > v(m, vector<int>(n, 0));
        
        for(int i = 0; i < n; ++i)
        {
            v[0][i] = 1;    
        }
        for(int i = 1; i < m; ++i)
        {
            v[i][0] = 1;
        }
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                v[i][j] = v[i - 1][j] + v[i][j - 1];
            }
        }
        
        return v[m - 1][n - 1];
    }
};
