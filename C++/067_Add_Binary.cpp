// https://oj.leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        string longer, shorter;
        if(a.size() > b.size())
        {
            longer = a;
            shorter = b;
        }
        else
        {
            longer = b;
            shorter = a;
        }
        
        int m = longer.size();
        int n = shorter.size();
        
        vector<char> v(m, '0');
        
        char carry = '0';
        
        for(int i = 1; i <= n; ++i)
        {
            if(longer[m - i] == '1' && shorter[n - i] == '1')
            {
                v[m - i] = carry;
                carry = '1';
            }
            else if(longer[m - i] == '0' && shorter[n - i] == '0') 
            {
                v[m - i] = carry;
                carry = '0';
            }
            else
            {
                if(carry == '1')
                {
                    v[m - i] = '0';
                }
                else
                {
                    v[m - i] = '1';
                }
            }
        }
        
        for(int i = m - n - 1; i >= 0; --i)
        {
            if(longer[i] == '1')
            {
                if(carry == '1')
                {
                    v[i] = '0';
                }
                else
                {
                    v[i] = '1';
                }
            }
            else
            {
                v[i] = carry;
                carry = '0';
            }
        }
        
        if(carry == '1')  // !
        {
            v.insert(v.begin(), '1');
        }
        
        return string(v.begin(), v.end());
    }
};


class Solution {
public:
    string addBinary(string a, string b) {
    	string str1;
    	string str2;

    	if(a.length() >= b.length())
    	{
    		str1 = a;
    		str2 = b;
    	}
    	else
    	{
    		str1 = b;
    		str2 = a;
    	}

    	int m = str1.length();
    	int n = str2.length();

    	char sum[m + 1];
    	sum[m] = '\0';

    	int i = m - 1;
    	char carry = '0';

    	--m;
    	--n;

    	while(n >= 0)
    	{
    		if(str1[m] == '0' && str2[n] == '0')
    		{
    			sum[i] = carry;
    			carry = '0';
    		}
    		else if(str1[m] == '1' && str2[n] == '1')
    		{
   				sum[i] = carry;
   				carry = '1';
    		}
    		else
    		{
    			if(carry == '0')
    			{
    				sum[i] = '1';
    			}
    			else
    			{
    				sum[i] = '0';
    			}
    		}
    		--m;
    		--n;
    		--i;
    	}

    	while(m >= 0)
    	{
    		if(str1[m] == '1')
    		{
    			if(carry == '0')
    			{
    				sum[i] = '1';
    			}
    			else
    			{
    				sum[i] = '0';
    			}
    		}
    		else
    		{
    			sum[i] = carry;
    			carry = '0';
    		}
    		--m;
    		--i;
    	}

    	string result = sum;

    	if(carry == '1')
    	{
    		return "1" + result;
    	}

    	return result;
    }
};

