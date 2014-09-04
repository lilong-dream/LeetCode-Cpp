// https://oj.leetcode.com/problems/powx-n/

class Solution {
public:
    double pow(double x, int n) {
        if(n < 0)
        {
            return 1.0 / helper(x, -n);
        }
        else
        {
            return helper(x, n);
        }
    }
    
    double helper(double x, int n)
    {
        if(n == 0)
        {
            return 1;
        }
        
        double res = pow(x, n / 2);
        
        if(n & 0x01)
        {
            return res * res * x;
        }
        else
        {
            return res * res;
        }
    }
};
