// https://oj.leetcode.com/problems/n-queens-ii/

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        
        col = vector<bool>(n, true);
        diag = vector<bool>(2 * n - 1, true);
        antidiag = vector<bool>(2 * n - 1, true);
        
        dfs(0, n, res);
        
        return res;
    }
    
private:
    vector<bool> col;
    vector<bool> diag;
    vector<bool> antidiag;
    
    void dfs(int i, int n, int &res)
    {
        if(i == n)
        {
            ++res;
            return;
        }
        
        for(int j = 0; j < n; ++j)
        {
            if(!(col[j] && diag[i - j + n - 1] && antidiag[i + j]))
            {
                continue;
            }
            
            col[j] = diag[i - j + n - 1] = antidiag[i + j] = false;  // antidiag
            
            dfs(i + 1, n, res);
            
            col[j] = diag[i - j + n - 1] = antidiag[i + j] = true;
        }
    }
};
