// https://oj.leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < 9; ++i)
        {
            vector<bool> v(9, false);    
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                if(v[board[i][j] - '1'])  // it's char
                {
                    return false;
                }
                v[board[i][j] - '1'] = true;    
            }
        }
        
        for(int j = 0; j < 9; ++j)
        {
            vector<bool> v(9, false);    
            for(int i = 0; i < 9; ++i)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                if(v[board[i][j] - '1'])
                {
                    return false;
                }
                v[board[i][j] - '1'] = true;    
            }
        }
        
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                vector<bool> v(9, false); 
                for(int m = i * 3; m < i * 3 + 3; ++m)
                {
                    for(int n = j * 3; n < j * 3 + 3; ++n)
                    {
                        if(board[m][n] == '.')
                        {
                            continue;
                        }
                        if(v[board[m][n] - '1'])
                        {
                            return false;
                        }
                        v[board[m][n] - '1'] = true; 
                    }
                }
            }
        }
        
        return true;
    }
};


class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool used[9];
		for(int i = 0; i < 9; ++i)
		{
			std::fill(used, used + 9, false);
			for(int j = 0; j < 9; ++j)
			{
				if(board[i][j] != '.')
				{
					if(used[board[i][j] - '1'])
					{
						return false;
					}
					else
					{
						used[board[i][j] - '1'] = true;
					}
				}
			}
		}

		for(int j = 0; j < 9; ++j)
		{
			std::fill(used, used + 9, false);
			for(int i = 0; i < 9; ++i)
			{
				if(board[i][j] != '.')
				{
					if(used[board[i][j] - '1'])
					{
						return false;
					}
					else
					{
						used[board[i][j] - '1'] = true;
					}
				}
			}
		}

		for(int i = 0; i < 9; i += 3)
		{
			for(int j = 0; j < 9; j += 3)
			{
				std::fill(used, used + 9, false);
				for(int m = i; m < i + 3; ++m)
				{
					for(int n = j; n < j + 3; ++n)
					{
						if(board[m][n] != '.')
						{
							if(used[board[m][n] - '1'])
							{
								return false;
							}
							else
							{
								used[board[m][n] - '1'] = true;
							}
						}
					}
				}
			}
		}

		return true;
    }
};

