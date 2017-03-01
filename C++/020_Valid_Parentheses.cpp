// Problem:  http://oj.leetcode.com/problems/valid-parentheses/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/21694751
// 1988lilong@163.com

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
    	if(s.length() == 0)
    	{
    		return true;
    	}

    	stack<char> st;
    	st.push(s[0]);

    	for(int i = 1; i < s.length(); ++i)
    	{
    		if(!st.empty() && isMatch(st.top(), s[i]))
    		{
    			st.pop();
    		}
    		else
    		{
    			st.push(s[i]);
    		}
    	}

    	if(st.empty())
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }

    bool isMatch(char s, char p)
    {
    	if((s == '(' && p == ')')
    	|| (s == '{' && p == '}')
    	|| (s == '[' && p == ']'))
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }
};

/*
int main()
{
	string s = "()";

	Solution slt;
	bool result = slt.isValid(s);
	if(result)
	{
		cout << "valid " << std::endl;
	}
	else
	{
		cout << "not valid " << std::endl;
	}

	return 0;
} */


class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
        {
            return true;
        }
        
        std::stack<char> st;
        
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else 
            {
                if(st.empty() || !match(st.top(), s[i]))  // order matters!
                {
                    return false;
                }
                st.pop();
            }
        }
        
        return st.empty() ? true : false;
    }
    
    bool match(char ch1, char ch2)
    {
        if(ch1 == '(' && ch2 == ')')
        {
            return true;
        }
        else if(ch1 == '[' && ch2 == ']')
        {
            return true;
        }
        else if(ch1 == '{' && ch2 == '}')
        {
            return true;
        }
        
        return false;
    }
};

