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
