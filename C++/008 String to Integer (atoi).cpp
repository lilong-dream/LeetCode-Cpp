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
