
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
		if(matrix.size() == 0) {
			return res;
		}
		int m = matrix.size();
		int n = matrix[0].size();
		int round = std::min((m + 1) / 2, (n + 1) / 2);
		for(int k = 0; k < round; ++k) {
			for(int j = k; j < n - k; ++j) {
				res.push_back(matrix[k][j]);
			}
			if(2 * k + 1 >= m) {
				break;
			}
			for(int i = k + 1; i < m - k; ++i) {
				res.push_back(matrix[i][n - k - 1]);
			}
			if(2 * k + 2 > n) {
				break;
			}
			for(int j = n - k - 2; j >= k; --j) {
				res.push_back(matrix[m - k - 1][j]);
			}
			if(2 * k + 2 >= m) {
				break;
			}
			for(int i = m - k - 2; i > k; --i) {
				res.push_back(matrix[i][k]);
			}
		}

		return res;
    }
};

