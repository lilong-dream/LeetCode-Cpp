// Given a string, find the length of the longest substring without repeating characters.

// int [26] 记录出现的最后位置

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        map<int, int> m;
        int ans = 0;
        
        while(end < s.size()) {
            if(m.find(s[end]) != m.end()) {
                ans = std::max(ans, end - start);
                for(int j = start; j < m[s[end]]; j++) {
                    m.erase(s[j]);
                }
                start = m[s[end]] + 1;
            }
            
            m[s[end]] = end;
            
            end++;
        }
        
        ans = std::max(ans, end - start);  //
        
        return ans;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int maxLen = 0;
        bool exist[256] = {false};
        while (j < n) {
            if (exist[s[j]]) {
                maxLen = max(maxLen, j - i);
                while (s[i] != s[j]) {
                    exist[s[i]] = false;
                    i++;
                }
                i++;
                j++;
            } else {
                exist[s[j]] = true;
                j++;
            }
        }
        maxLen = max(maxLen, n - i);
        return maxLen;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) {
			return 0;
		}
		if(s.size() == 1) {
			return 1;
		}
		int i = 0;
		int j = 0;
		int maxl = 0;
		std::map<char, bool> table;
		while ( (i < s.size()) && (j < s.size()) )
		{
			if (table[s[j]] == false)
			{ 
				table[s[j]] = true;
				maxl = std::max(maxl, j - i + 1);
				j++; 
			}
			else if (table[s[j]] == true)
			{
				maxl = std::max(maxl, j - i);
				table[s[i]] = false;
				i++;
			}
		}
		
		return maxl;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		int length = s.length();
		if(length == 1)
		{
			return 1;
		}

		int longest = 0;
		int len = 0;
		string tmp;

		for(int i = 0; i < length; ++i)
		{
			if(longest > length - i)
			{
				break;
			}

			len = 0;
			for(int j = i + 1; j < length; ++j)
			{
				++len;

				tmp = s.substr(i, j - i);  // !
				auto pos = tmp.find(s[j]);
				if(pos != string::npos)
				{
					i += pos;

					int k = j;
					while((++k < length) && (s[i + 1] == s[k]))
					{
						++i;
					}

					if(longest < len)
					{
						longest = len;
					}

					break;
				}

				if(j == length -1)
				{
					longest = len + 1;
					break;
				}
			}
		}

		return longest;
    }
};

