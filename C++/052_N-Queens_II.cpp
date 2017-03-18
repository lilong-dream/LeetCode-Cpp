// https://oj.leetcode.com/problems/n-queens-ii/

// Hard

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


class Solution {
public:
    int totalNQueens(int n) {
        columns = vector<int>(n, 0);
		main_diag = vector<int>(2 * n, 0);
		anti_diag = vector<int>(2 * n, 0);

		int res = 0;
		dfs(n, res, 0);

		return res;
	}

	void dfs(int n, int &count, int row)
	{
		if(row == n)
		{
			++count;
			return;
		}

		for(int j = 0; j < n; ++j)
		{
			const bool ok = columns[j] == 0 && main_diag[row - j + n] == 0 &&
				anti_diag[row + j] == 0;
			if(!ok)
			{
				continue;
			}
			columns[j] = main_diag[row - j + n] = anti_diag[row + j] = 1;
			dfs(n, count, row + 1);
			columns[j] = main_diag[row - j + n] = anti_diag[row + j] = 0;
		}
	}
private:
	vector<int> columns;
	vector<int> main_diag;
	vector<int> anti_diag;
};

