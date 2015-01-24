// https://oj.leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        if(n == 0 || s[0] == '0')
        {
            return 0;    
        }
        
        vector<int> way(n + 1, 0);
        
        way[0] = 1;
        way[1] = 1;
        
        for(int i = 2; i <= s.size(); ++i)
        {
            if(s[i - 1] != '0')
            {
                way[i] = way[i - 1];
            }
            
            if((s[i - 2] == '1') || (s[i - 2] == '2' && s[i - 1] <= '6'))
            {
                way[i] += way[i - 2];
            }
        }
        
        return way[n];
    }
};
