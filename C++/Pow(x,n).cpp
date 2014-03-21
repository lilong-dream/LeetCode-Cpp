// Problem:  http://oj.leetcode.com/problems/powx-n/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/21701775
// 1988lilong@163.com

#include <iostream>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
    	if(n < 0)
    	{
    	    return 1.0 / power(x, -n);
    	}
    	else
    	{
        	return power(x, n);
    	}
    }

    double power(double x, int n) {
    	if(n == 0)
    	{
    		return 1;
    	}

    	double tmp = pow(x, n / 2);

    	if(n & 0x01)
    	{
    	    return tmp * tmp * x;
    	}
    	else
    	{
    	    return tmp * tmp;
    	}
    }
};

/*
int main()
{
	Solution slt;
	double result = slt.pow(1, -2147483648);
	cout << result << endl;
} */
