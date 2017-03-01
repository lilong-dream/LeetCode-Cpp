// Problem:  http://oj.leetcode.com/problems/integer-to-roman/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/22869803
// 1988lilong@163.com

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    string intToRoman(int num) {
    	const int base[] = {1000, 900, 500, 400, 100, 90, 50,
    			40, 10, 9, 5, 4, 1};
    	const string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L",
    			"XL", "X", "IX", "V", "IV", "I"};

    	string result;

    	for(int i = 0; num > 0; ++i)
    	{
    		int count = num / base[i];
    		num %= base[i];

    		while(count > 0)
    		{
    			result += roman[i];
    			--count;
    		}
    	}

    	return result;
    }
};

int main()
{
	Solution slt;
	string result = slt.intToRoman(321);
	std::cout << result << std::endl;

	return 0;
}

