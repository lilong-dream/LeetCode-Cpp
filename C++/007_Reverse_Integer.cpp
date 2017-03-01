// https://oj.leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        
        if(x < 0)
        {
            sign = -1;
            x = -x;
        }
        
        int res = 0;
        
        while(x != 0)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        
        return sign * res;
    }
};


class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        int flag = 1;
        int m = x;
        if(x < 0) {
            flag = -1;
            m = -x;
        }
        while(m / 10) {
            res = res * 10 + m % 10;
            m /= 10;
        }
        
        res = res * 10 + m % 10;
        
        if(res * flag > 2147483647 || res * flag < -2147483648) {
            return 0;
        } else {
            return res * flag;
        }
    }
};

