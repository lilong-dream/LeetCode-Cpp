
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        
        int m = grid.size();
        if(m == 0) {
            return res;
        }
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '0') {  //
                    continue;
                }
                res++;
                dfs(grid, i, j, m, n);
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if(grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n) {
                dfs(grid, x, y, m, n);
            }
        }
    }
};

