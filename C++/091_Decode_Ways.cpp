// https://oj.leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        if(n == 0 || s[0] == '0') {
            return 0;    
        }
        
        vector<int> way(n + 1, 0);
        
        way[0] = 1;
        way[1] = 1;
        
        for(int i = 2; i <= s.size(); ++i) {
            if(s[i - 1] != '0') {
                way[i] = way[i - 1];
            }
            
            if((s[i - 2] == '1') || (s[i - 2] == '2' && s[i - 1] <= '6')) {
                way[i] += way[i - 2];
            }
        }
        
        return way[n];
    }
};


class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0')
		{
			return 0;
		}
		
		vector<int> a(s.length(), 0);
		a[0] = 1;
		
		for(int i = 1; i < s.length(); ++i)
		{
			if(s[i] != '0')
			{
				a[i] += a[i - 1];
			}
			
			int c = 0;
			if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
			{
				if(i >= 2)
				{
					c = a[i - 2];
				}
				else
				{
					c = 1;
				}
			}
			a[i] += c;
		}
		
		return a[s.length() - 1];
    }
};

