// Problem:  http://oj.leetcode.com/problems/generate-parentheses/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/23917967
// 1988lilong@163.com

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> res;
    	generate(n, n, "", res);
    	return res;
    }

    void generate(int left, int right, string str, vector<string>& res) {
    	if(left == 0 && right == 0) {
    		res.push_back(str);
    		return;
    	}

    	if(left > 0) {
    		generate(left - 1, right, str + '(', res);
    	}

    	if(right > left) {
    		generate(left, right - 1, str + ')', res);
    	}
    }
};

int main()
{
	Solution slt;
	vector<string> result = slt.generateParenthesis(3);
	for(int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << std::endl;
	}

	return 0;
}


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, 0, 0, "", res);
        return res;
    }
    
    void helper(int n, int left, int right, string cur, vector<string> &res) {
        if(left == n) {
            cur.append(n - right, ')');
            res.push_back(cur);
            return;
        }
        
        helper(n, left + 1, right, cur + '(', res);

        if(left > right) {
            helper(n, left, right + 1, cur + ')', res);
        }
    }
};

