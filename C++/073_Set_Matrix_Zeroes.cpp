
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
    	const int m = matrix.size();
    	const int n = matrix[0].size();
    	bool row = false;
    	bool column = false;

    	for(int i = 0; i < m; ++i) {
    		if(matrix[i][0] == 0) {
    			row = true;
    			break;
    		}
    	}

    	for(int j = 0; j < n; ++j) {
    		if(matrix[0][j] == 0) {
    			column = true;
    			break;
    		}
    	}

    	for(int i = 1; i < m; ++i) {
    		for(int j = 1; j < n; ++j) {
    			if(matrix[i][j] == 0) {
    				matrix[0][j] = 0;
    				matrix[i][0] = 0;
    			}
    		}
		}

    	for(int i = 1; i < m; ++i) {
    		if(matrix[i][0] == 0) {
    			for(int j = 1; j < n; ++j) {
    				matrix[i][j] = 0;
    			}
    		}
    	}

    	for(int j = 1; j < n; ++j) {
    		if(matrix[0][j] == 0) {
    			for(int i = 1; i < m; ++i) {
    				matrix[i][j] = 0;
    			}
    		}
    	}

    	if(row) {
    		for(int i = 0; i < m; ++i) {
    		    matrix[i][0] = 0;
    		}
    	}

    	if(column) {
    		for(int j = 0; j < n; ++j) {
    		    matrix[0][j] = 0;
    		}
    	}
    }
};

