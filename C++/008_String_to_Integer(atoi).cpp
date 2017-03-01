// https://oj.leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int atoi(const char *str) {
        if(str == NULL)
        {
            return 0;
        }
        
        while(*str == ' ')
        {
            ++str;
        }
        
        int sign = 1;
        
        if(*str == '+' || *str == '-')
        {
            if(*str == '-')
            {
                sign = -1;
            }
            ++str;
        }
        
        long long res = 0;  // don't use int! 
        
        while(*str)
        {
            if(*str >= '0' && *str <= '9')
            {
                res = res * 10 + (*str - '0');
                if(res > INT_MAX)
                {
                    if(sign == -1)
                    {
                        return INT_MIN;
                    }
                    return INT_MAX;
                }
                ++str;
            }
            else
            {
                break;
            }
        }
        
        return sign * res;
    }
};


class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int i = 0;
        int flag = 1;
        
        if(str.length() == 0) {
            return res;
        }
        while(str[i] == ' ') {
            i++;
        }
        if(str[i] == '+' || str[i] == '-') {
            if(str[i] == '-') {
                flag = -1;
            }
            i++;
        }
        while(i < str.length()) {
            if(str[i] >= '0' && str[i] <= '9') {
                if(res * 10 + (str[i] - '0') > ((1 << 31) - 1)) {
                    if(flag == 1) {
                        return (1 << 31) - 1;
                    } else {
                        return -(1 << 31);
                    }
                } else {
                    res = res * 10 + (str[i] - '0');
                }
            } else {
                return res * flag;
            }
            i++;
        }

        return res * flag;
    }
};

class Solution {
public:
    int atoi(const char *str) {
    	if(str == NULL)
    	{
    		return 0;
    	}

    	int i = 0;
    	while(str[i] == ' ')
		{
			++i;
		}

		int sign = 1;
		if(str[i] == '-')
		{
			sign = -1;
			++i;
		}
		else if(str[i] == '+')
		{
			++i;
		}

		long long res = 0;
    	while(str[i] != '\0')
    	{
    		if(str[i] >= '0' && str[i] <= '9')
    		{
    			res = res * 10 + (str[i] - '0');

    			if(res > INT_MAX)
    			{
    				return sign == -1 ? INT_MIN : INT_MAX;
    			}
    		}
    		else
    		{
    			break;
    		}

    		++i;
    	}

		return sign * res; 
    }
};

