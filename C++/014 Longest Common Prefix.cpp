// https://oj.leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty())
        {
            return "";
        }
        
        for(int len = 0; len < strs[0].size(); ++len)
        {
            for(int i = 1; i < strs.size(); ++i)
            {
                if(strs[i].size() <= len || (strs[i][len] != strs[0][len]))  // !
                {
                    return strs[0].substr(0, len);  // return string not length
                }
            }
        }
        
        return strs[0];
    }
};
