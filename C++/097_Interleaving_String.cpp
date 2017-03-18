
// Hard

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
		int len2 = s2.size();
		
		if(s3.size() != len1 + len2) {
			return false;
		}

		vector<vector<bool> > f(len1 + 1, vector<bool>(len2 + 1, true));

		//memset(f, true, sizeof(f));

		for(int i = 1; i <= len1; ++i) {
			f[i][0] = (s1[i - 1] == s3[i - 1]) && f[i - 1][0];
		}

		for(int j = 1; j <= len2; ++j) {
			f[0][j] = (s2[j - 1] == s3[j - 1]) && f[0][j - 1];
		}

		for(int i = 1; i <= len1; ++i) {
			for(int j = 1; j <= len2; ++j) {
				f[i][j] = ((s1[i - 1] == s3[i + j - 1]) && f[i - 1][j]) ||
					((s2[j - 1] == s3[i + j - 1]) && f[i][j - 1]);	    

			}
		}

		return f[len1][len2];  
    }
};

