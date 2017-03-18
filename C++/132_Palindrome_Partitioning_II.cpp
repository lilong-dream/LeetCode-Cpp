
// Hard

class Solution {
public:
    int minCut(string s) {
        if(s.empty()) {
			return 0;
		}

		int len = s.size();

		vector<int> f(len + 1, 0); 
		vector<vector<bool> > p(len, vector<bool>(len, false));

		for(int i = 0; i <= len; ++i) {
			f[i] = len - i - 1;  // start from back
		}

		for(int i = len - 1; i >= 0; --i) {
			for(int j = i; j < len; ++j) {
				if(s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
					p[i][j] = true;
					f[i] = std::min(f[i], f[j + 1] + 1);  // 
				}
			}
		}

		return f[0];
    }
};

