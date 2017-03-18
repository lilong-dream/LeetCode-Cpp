
// TODO
// Hard
// DP

// Given a string S and a string T, count the number of distinct subsequences of T in S.
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
// Here is an example:
// S = "rabbbit", T = "rabbit"
// Return 3.

class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.size();
        int n = T.size();
        
        vector<vector<int> > f(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 0; i < m; ++i) {
            f[i][0] = 1;
        }
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                f[i][j] = f[i - 1][j]; 
                if(S[i - 1] == T[j - 1]) {
                    f[i][j] += f[i - 1][j - 1];
                }
            }
        }
        
        return f[m][n];
    }
};

