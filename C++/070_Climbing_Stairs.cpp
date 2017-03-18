// Problem:  http://oj.leetcode.com/problems/climbing-stairs/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/21650907
// 1988lilong@163.com

#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
		int a[n + 1];  // vector
		a[0] = 1;
		a[1] = 1;

		for(int i = 2; i <= n; ++i) {
			a[i] = a[i - 1] + a[i - 2];
		}

		return a[n];
	}
};

/*
int main()
{
	Solution slt;

	int result = slt.climbStairs(3);

	std::cout << result <<std::endl;
} */


class Solution {
public:
    int climbStairs(int n) {
        int p = 1;
        int q = 1;
        
        for(int i = 1; i < n; ++i)
        {
            int m = q;
            q = p + q;
            p = m;
        }
        
        return q;
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) {
            return 1;
        }
        if(n == 2) {
            return 2;
        }
        int pre2 = 1;
        int pre1 = 2;
        for(int i = 3; i <= n; i++) {
            int cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        
        return pre1;
    }
};

