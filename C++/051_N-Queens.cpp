// https://oj.leetcode.com/problems/n-queens/

// Hard

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
    
    void dfs(int i, int n, vector<vector<string> > &res, vector<string> &board) {
        if(i == n) {
            res.push_back(board);
            return;
        }
        
        for(int j = 0; j < n; ++j) {
            if(!(col[j] && diag[i - j + n - 1] && antidiag[i + j])) {
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


class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        columns = vector<int>(n, 0);
		main_diag = vector<int>(2 * n, 0);
		anti_diag = vector<int>(2 * n, 0);

        vector<vector<string> > res;
		vector<int> C(n, 0);
		dfs(C, res, 0);

		return res;
    }

	void dfs(vector<int> &C, vector<vector<string> > &res, int row)
	{
		const int N = C.size(); 
		if(row == N)
		{
			vector<string> cur;
			for(int i = 0; i < N; ++i)
			{
				string s(N, '.');
				for(int j = 0; j < N; ++j)
				{
					if(j == C[i])
					{
						s[j] = 'Q';
					}
				}
				cur.push_back(s);
			}
			res.push_back(cur);
			return;
		}

		for(int j = 0; j < N; ++j)
		{
			const bool ok = columns[j] == 0 && main_diag[row - j + N] == 0 &&
				anti_diag[row + j] == 0;
			if(!ok)
			{
				continue;
			}
			C[row] = j;
			columns[j] = main_diag[row - j + N] = anti_diag[row + j] = 1;
			dfs(C, res, row + 1);
			//C[row] = 0; // ?
			columns[j] = main_diag[row - j + N] = anti_diag[row + j] = 0;
		}
	}
private:
	vector<int> columns;
	vector<int> main_diag;
	vector<int> anti_diag;
};

