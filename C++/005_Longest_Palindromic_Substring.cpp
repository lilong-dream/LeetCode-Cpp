
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int longestBegin = 0;
        int maxLen = 1;

        bool table[1000][1000] = {false};
        for (int i = 0; i < n; i++) {
            table[i][i] = true;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                table[i][i + 1] = true;
                longestBegin = i;
                maxLen = 2;
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && table[i + 1][j - 1]) {
                    table[i][j] = true;
                    longestBegin = i;
                    maxLen = len;
                }
            }
        }

        return s.substr(longestBegin, maxLen);
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
		string str;
		if(len > 0) {
			str = s.substr(0, 1);
		}
		for(int i = 0; i < len - 1; ++i)
		{
			if(s[i] == s[i + 1])
			{
				string str1 = helper(s, i, i + 1);
				if(str1.size() > str.size())
				{
					str = str1;
				}
			}

			string str2 = helper(s, i, i);
			if(str2.size() > str.size())
			{
				str = str2;
			}
		}

		return str;
	}

	string helper(string s, int start, int end)
	{
		int len = s.size();
		int left = start;
		int right = end;
		while(left >= 0 && right < len && s[left] == s[right])
		{
			--left;
			++right;
		}

		return s.substr(left + 1, right - 1 - left);
    }
};

