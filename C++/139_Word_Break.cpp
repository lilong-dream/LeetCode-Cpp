// https://oj.leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty()) {
            return true;
        }
        
        int len = s.size();
        
        vector<bool> f(len + 1, false);
        
        f[0] = true;
        
        for(int i = 1; i <= len; ++i) {
            for(int j = 0; j < i; ++j) {  // for(int j = i - 1; j >= 0; --j)
                if(f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    f[i] = true;  // f[i] means from 0 to (i - 1)
                    break;
                }
            }
        }
        
        return f[len];
    }
};

