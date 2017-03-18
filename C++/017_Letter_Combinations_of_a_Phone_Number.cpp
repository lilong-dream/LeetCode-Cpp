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
    
    void dfs(const string &digits, int start, string &cur, vector<string> &res) {
        if(start == digits.size()) {
            res.push_back(cur);
            return;
        }
        
        int index = digits[start] - '0';
        for(int i = 0; i < phone[index].size(); ++i) {
            cur.push_back(phone[index][i]);
            
            dfs(digits, start + 1, cur, res);
            
            cur.pop_back();
        }
    }
};


class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	const string letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    	vector<string> result(1, "");
    	for(int i = 0; i < digits.size(); ++i)
    	{
    		for(int j = result.size() - 1; j >= 0; --j)
    		{
    			const string& s = letters[digits[i] - '2'];

    			for(int k = s.size() - 1; k >= 0; --k)
    			{
    				if(k)
    				{
    					result.push_back(result[j] + s[k]);
    				}
    				else
    				{
    					result[j] += s[k];
    				}
    			}
    		}
    	}

    	return result;
    }
};

