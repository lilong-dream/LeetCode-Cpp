// Problem:  http://oj.leetcode.com/problems/implement-strstr/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/23655843
// 1988lilong@163.com

#include <iostream>
#include <string>

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
    	std::string str(haystack);
    	std::string target(needle);

    	if(target.empty())
    	{
    		return haystack;
    	}

    	int len1 = str.length();
    	int len2 = target.length();
    	if(len1 < len2)
    	{
    		return NULL;
    	}

    	for(int i = 0; i <= len1 - len2; ++i)
    	{
    		int j = 0;
    		int k = i;
    		while(j < len2 && target[j] == str[k])
    		{
    			k++;
    			j++;
    		}

    		if(j == len2)
    		{
    			return (char*)str.substr(i).c_str();
    		}
    	}

    	return NULL;
    }
};

int main()
{
	char *a = "abcdab";
	char *needle = "da";

	Solution slt;
	std::cout << slt.strStr(a, needle) << std::endl;
}
