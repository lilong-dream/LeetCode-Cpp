// https://oj.leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> cur;
        dfs(s, 0, cur, res);
        return res;
    }
    
    void dfs(const string &s, int start, vector<string> &cur, vector<vector<string> > &res)
    {
        if(start == s.size())
        {
            res.push_back(cur);
            return;
        }
        
        for(int i = start + 1; i <= s.size(); ++i)
        {
            string tmp = s.substr(start, i - start);
            if(isPalindrome(tmp))
            {
                cur.push_back(tmp);
                dfs(s, i, cur, res);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string &s)
    {
        int i = 0; 
        int j = s.size() - 1;  // !
        
        while(i < j)
        {
            if(s[i++] != s[j--])
            {
                return false;
            }
        }
        
        return true;
    }
};

