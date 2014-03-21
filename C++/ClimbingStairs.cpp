// Problem:  http://oj.leetcode.com/problems/climbing-stairs/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/21650907
// 1988lilong@163.com

#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
		int a[n + 1];
		a[0] = 1;
		a[1] = 1;

		for(int i = 2; i <= n; ++i)
		{
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
