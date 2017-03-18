// https://oj.leetcode.com/problems/word-break-ii/

// Hard

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
		
		if(s.empty()) {
			return res;
		}
			
		int len = s.length();
		vector<bool> f(len + 1, false);
		f[0] = true;
		
		for(int i = 1; i <= len; ++i) {
			for(int j = 0; j < i; ++j) {
				if(f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					f[i] = true;
					break;
				}
			}
		}
		
		if(!f[len]) {
			return res;
		}
		
		dfs(s, 0, dict, "", res);
		
		return res;
    }
	
	void dfs(const string &s, int start, unordered_set<string> &dict, const string &curWord, vector<string> &res) {
		if(start == s.length()) {
			res.push_back(curWord);
			return;
		}
		
		for(int i = start + 1; i <= s.length(); ++i) {
			string word = s.substr(start, i - start); 
			if(dict.find(word) != dict.end()) {
				string newWord = curWord.empty() ? word : curWord + " " + word;
				dfs(s, i, dict, newWord, res);
			}
		}
	}
};


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;

		if(s.empty())
		{
			return res;
		}

		int len = s.length();
		vector<bool> f(len + 1, false);
		f[0] = true;

		for(int i = 1; i <= len; ++i)
		{
			for(int j = 0; j < i; ++j)
			{
				if(f[j] && find(wordDict.begin(),wordDict.end(),s.substr(j, i - j)) != wordDict.end())
				{
					f[i] = true;
					break;
				}
			}
		}

		if(!f[len])
		{
			return res;
		}

		dfs(s, 0, wordDict, "", res);

		return res;
    }

	void dfs(const string &s, int start, vector<string>& dict, const string &curWord, vector<string> &res)
	{
		if(start == s.length())
		{
			res.push_back(curWord);
			return;
		}

		for(int i = start + 1; i <= s.length(); ++i)
		{
			string word = s.substr(start, i - start);
			if(find(dict.begin(), dict.end(), word) != dict.end())
			{
				string newWord = curWord.empty() ? word : curWord + " " + word;
				dfs(s, i, dict, newWord, res);
			}
		}
	}
};

