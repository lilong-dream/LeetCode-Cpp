// https://oj.leetcode.com/problems/n-queens/

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;  // n == 1 has result
        
        col = vector<bool>(n, true);
        diag = vector<bool>(2 * n - 1, true);
        antidiag = vector<bool>(2 * n - 1, true);
    
        vector<string> board(n, string(n, '.'));  
        
        dfs(0, n, res, board);
        
        return res;
    }

private:
    vector<bool> col;
    vector<bool> diag;
    vector<bool> antidiag;
    
    void dfs(int i, int n, vector<vector<string> > &res, vector<string> &board)
    {
        if(i == n)
        {
            res.push_back(board);
            return;
        }
        
        for(int j = 0; j < n; ++j)
        {
            if(!(col[j] && diag[i - j + n - 1] && antidiag[i + j]))
            {
                continue;        
            }
            
            board[i][j] = 'Q';  // i
            col[j] = diag[i - j + n - 1] = antidiag[i + j] = false;
            
            dfs(i + 1, n, res, board);
            
            board[i][j] = '.';
            col[j] = diag[i - j + n - 1] = antidiag[i + j] = true;
        }
    }
};
