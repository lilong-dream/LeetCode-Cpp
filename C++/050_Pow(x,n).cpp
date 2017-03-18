// Problem:  http://oj.leetcode.com/problems/powx-n/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/21701775
// 1988lilong@163.com

#include <iostream>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if(n < 0) {
            return 1.0 / helper(x, -n);
        } else {
            return helper(x, n);
        }
    }
    
    double helper(double x, int n) {
        if(n == 0) {
            return 1;
        }
        
        double res = pow(x, n / 2);
        
        if(n & 0x01) {
            return res * res * x;
        } else {
            return res * res;
        }
    }
};


class Solution {
    public:
    double powx(double x, long n) {
        if(n == 0) {
            return 1;
        }
        if(n == 1) {
            return x;
        }
        double res = powx(x, n / 2);
        if(n % 2 == 1) {
            return res * res * x;
        } else {
            return res * res;
        }
    }
    
    double myPow(double x, int n) {
        if(x == 1) {
            return 1;
        }
        if(n == 0) {
            return 1;
        } else if(n > 0) {
            return powx(x, n);
        } else {
            long nn = n;
            return 1.0 / powx(x, -nn);
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

