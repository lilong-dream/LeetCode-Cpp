
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;

    	map<char, int> m;
    	m['I'] = 1;
    	m['V'] = 5;
    	m['X'] = 10;
    	m['L'] = 50;
    	m['C'] = 100;
    	m['D'] = 500;
    	m['M'] = 1000;

    	for(int i = 0; i < s.size(); ++i)
    	{
    		if(i > 0 && m[s[i]] > m[s[i - 1]])
    		{
    			result = result + m[s[i]] - 2 * m[s[i - 1]];
    		}
    		else
    		{
    			result += m[s[i]];
    		}
    	}

    	return result;
    }
};

