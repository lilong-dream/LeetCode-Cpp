
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1) {
    		return 0;
    	}
    	
        vector<vector<int> > f(m, vector<int>(n, 0));
        
        for(int i = 0; i < n; ++i) {
            if(obstacleGrid[0][i] != 1) {
                f[0][i] = 1;
            } else {
                break;
            }
        }
        for(int i = 1; i < m; ++i) {
            if(obstacleGrid[i][0] != 1) {
                f[i][0] = 1;
            } else {
                break;
            }
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(obstacleGrid[i][j] != 1) {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                } else {
                    f[i][j] = 0;
                }
            }
        }
        
        return f[m - 1][n - 1];
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    	int m = obstacleGrid.size();
    	int n = obstacleGrid[0].size();

    	if(obstacleGrid[0][0] == 1)
    	{
    		return 0;
    	}
    	else if(m == 1 && n == 1)
    	{
    		return 1;
    	}

    	int paths[m][n];

    	for(int i = 0; i < m; ++i)
    	{
    		if(obstacleGrid[i][0] == 1)
    		{
    			while(i < m)
    			{
    				paths[i][0] = 0;
    				++i;
    			}
    			break;
    		}
    		else
    		{
    			paths[i][0] = 1;
    		}
    	}

    	for(int j = 1; j < n; ++j)
        {
        	if(obstacleGrid[0][j] == 1)
        	{
        		while(j < n)
        		{
        			paths[0][j] = 0;
        			++j;
        		}
        		break;
        	}
        	else
        	{
        		paths[0][j] = 1;
        	}
        }

    	for(int i = 1; i < m; ++i)
    		for(int j = 1; j < n; ++j)
    		{
    			if(obstacleGrid[i][j] == 1)
    			{
    				paths[i][j] = 0;
    			}
    			else
    			{
    				paths[i][j] = paths[i][j - 1] + paths[i - 1][j];
    			}
    		}

    	return paths[m - 1][n - 1];
    }
};

