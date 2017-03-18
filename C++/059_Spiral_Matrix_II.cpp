
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n));
		int i = 0; 
		int j = -1;
		int num = 1;
		for(int k = 0; k < (n + 1) / 2; ++k) {
			for(int dir1 = 0; dir1 < n - 2 * k; ++dir1) {
				++j;
				res[i][j] = num++;
			}
			for(int dir2 = 0; dir2 < n - 1 - 2 * k; ++dir2) {
				++i;
				res[i][j] = num++;
			}
			for(int dir3 = 0; dir3 < n - 1 - 2 * k; ++dir3) {
				--j;
				res[i][j] = num++;
			}
			for(int dir4 = 0; dir4 < n - 2 - 2 * k; ++dir4) {
				--i;
				res[i][j] = num++;
			}
		}

		return res;
    }
};

