
// Hard

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
		dfs(board, 0, 0);
	}

	bool dfs(vector<vector<char> > &board, int i, int j)
	{
		if(j == 9)
			return dfs(board, i + 1, 0);
		if(i == 9)
			return true;

		if(board[i][j] == '.')
		{
			for(int k = 1; k <= 9; ++k)
			{
				board[i][j] = char(k + '0');

				if(isValid(board, i, j) && dfs(board, i, j + 1))
				{
					return true;
				}

				board[i][j] = '.';
			}
		}
		else
		{
			return dfs(board, i, j + 1);
		}

		return false;
	}

	bool isValid(vector<vector<char> > &board, int i, int j)
	{
		for(int k = 0; k < 9; ++k)
		{
			if(k != j && board[i][k] == board[i][j])
			{
				return false;
			}
			if(k != i && board[k][j] == board[i][j])
			{
				return false;
			}
		}

		for(int k = i / 3 * 3; k < i / 3 * 3 + 3; ++k)
		{
			for(int m = j / 3 * 3; m < j / 3 * 3 + 3; ++m)
			{
				if((k != i || m != j) && board[k][m] == board[i][j])
				{
					return false;
				}
			}
		}

		return true;
    }
};

