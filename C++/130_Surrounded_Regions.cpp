// https://oj.leetcode.com/problems/surrounded-regions/

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        
        if(m < 3)  //
        {
            return;    
        }
        
        int n = board[0].size();
        
        if(n < 3)
        {
            return;    
        }
        
        for(int j = 0; j < n; ++j)
        {
            if(board[0][j] == 'O')
            {
                bfs(0, j, board);
            }
            if(board[m - 1][j] == 'O')
            {
                bfs(m - 1, j, board);
            }
        }
        
        for(int i = 0; i < m; ++i)
        {
            if(board[i][0] == 'O')
            {
                bfs(i, 0, board);
            }
            if(board[i][n - 1] == 'O')
            {
                bfs(i, n - 1, board);
            }
        }
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == '.')
                {
                    board[i][j] = 'O';
                }
                else
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    void bfs(int xx, int yy, vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        
        std::queue<std::pair<int, int> > q;
        
        board[xx][yy] = '.';
        q.push(std::make_pair(xx, yy));
        
        while(!q.empty())
        {
            int x = q.front().first;  // ()
            int y = q.front().second;
            
            q.pop();  // !!
            
            for(int i = 0; i < 4; ++i)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if(newX >= 0 && newX < m && newY >= 0 && newY < n)
                {
                    if(board[newX][newY] == 'O')
                    {
                        board[newX][newY] = '.';
                        q.push(std::make_pair(newX, newY));  
                    }
                }
            }
        }
    }
};


int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty())
        {
            return;
        }
        int m = board.size();
        int n = board[0].size();
        // if(m < 3 || n < 3)
        // {
        //     return;
        // }
        for(int j = 0; j < n; ++j)
        {
            if(board[0][j] == 'O')
            {
                bfs(board, 0, j);
            }
            if(board[m - 1][j] == 'O')
            {
                bfs(board, m - 1, j);
            }
        }
        for(int i = 1; i < m - 1; ++i)
        {
            if(board[i][0] == 'O')
            {
                bfs(board, i, 0);
            }
            if(board[i][n - 1] == 'O')
            {
                bfs(board, i, n - 1);
            }
        }
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] != '.')
                {
                    board[i][j] = 'X';
                }
                else
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void bfs(vector<vector<char>> &board, int row, int col)
    {
        int m = board.size();
        int n = board[0].size();
        
        std::queue<pair<int, int> > q;
        board[row][col] = '.';
        q.push(make_pair(row, col));
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();  // !
            
            for(int i = 0; i < 4; ++i)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n
                    && board[newX][newY] == 'O')
                {
                    board[newX][newY] = '.';
                    q.push(make_pair(newX, newY));
                }
            }
        }
    }
};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty())
		{
			return;
		}

		int m = board.size();
		int n = board[0].size();
		for(int i = 0; i < m; ++i)
		{
			bfs(board, i, 0);
			bfs(board, i, n - 1);
		}
		for(int j = 0; j < n; ++j)
		{
			bfs(board, 0, j);
			bfs(board, m - 1, j);
		}

		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
			{
				if(board[i][j] == 'O')
				{
					board[i][j] = 'X';
				}
				else if(board[i][j] == '+')
				{
					board[i][j] = 'O';
				}
			}
    }

	void bfs(vector<vector<char>> &board, int i, int j)
	{
		int m = board.size();
		int n = board[0].size();
		std::queue<int> q;
		visit(board, i, j, q);
		while(!q.empty())
		{
			int a = q.front();
			q.pop();
			int b = a / n;
			int c = a % n;
			visit(board, b + 1, c, q);
			visit(board, b - 1, c, q);
			visit(board, b, c + 1, q);
			visit(board, b, c - 1, q);
		}
	}

	void visit(vector<vector<char>> &board, int i, int j, std::queue<int> &q)
	{
		int m = board.size();
		int n = board[0].size();
		if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
		{
			return;
		}
		board[i][j] = '+';
		q.push(i * n + j);
    }
};

