// https://oj.leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        if(m == 0) {
            return 0;
        }
        if(m == 1) {
            return triangle[0][0];
        }
        
        vector<int> v(m, 0);
        v[0] = triangle[0][0];
        
        for(int i = 1; i < m; ++i) {
            v[i] = v[i - 1] + triangle[i][i];
            
            for(int j = i - 1; j > 0; --j) {
                v[j] = std::min(v[j], v[j - 1]) + triangle[i][j];
            }
            
            v[0] += triangle[i][0];
        }
        
        int min = v[0];
        
        for(int i = 1; i < m; ++i) {
            if(v[i] < min) {
                min = v[i];
            }
        }
        
        return min;
    }
};

