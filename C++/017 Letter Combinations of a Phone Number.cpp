// https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/

string phone[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        
        string cur = "";
        
        dfs(digits, 0, cur, res);
        
        return res;
    }
    
    void dfs(const string &digits, int start, string &cur, vector<string> &res)
    {
        if(start == digits.size())
        {
            res.push_back(cur);
            return;
        }
        
        int index = digits[start] - '0';
        for(int i = 0; i < phone[index].size(); ++i)
        {
            cur.push_back(phone[index][i]);
            
            dfs(digits, start + 1, cur, res);
            
            cur.pop_back();
        }
    }
};
