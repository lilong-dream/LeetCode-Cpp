// https://oj.leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        
        if(numRows == 0) {
            return res;
        }
        
        for(int i = 0; i < numRows; ++i) {
            vector<int> v(i + 1, 1);
            
            for(int j = 1; j < i; ++j) {
                v[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            
            res.push_back(v);
        }
        
        return res;
    }
};


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
		if(numRows == 0) {
			return res;
		}
		vector<int> cur(1, 1);
		res.push_back(cur);
        for(int i = 1; i < numRows; ++i) {
			cur.resize(i + 1, 1);
			for(int j = i - 1; j > 0; --j)
			{
				cur[j] += cur[j - 1];
			}
			res.push_back(cur);
		}

		return res;
    }
};

