
class Solution {
public:
    int minCut(string s) {
        if(s.empty())
		{
			return 0;
		}
		int len = s.size();

		vector<int> f(len + 1, false); // ?
		vector<vector<bool> > ff(len, vector<bool>(len, false));

		for(int i = 0; i <= len; ++i)
		{
			f[i] = len - i - 1;
		}

		for(int i = len - 1; i >= 0; --i)
		{
			for(int j = i; j < len; ++j)
			{
				if(s[i] == s[j] && (j - i < 2 || ff[i + 1][j - 1]))
				{
					ff[i][j] = true;
					f[i] = std::min(f[i], f[j + 1] + 1); // ? + 1
				}
			}
		}

		return f[0];
    }
};

