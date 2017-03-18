// Problem:  http://oj.leetcode.com/problems/longest-common-prefix/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/22886331
// 1988lilong@163.com

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
    	if(strs.empty()) {
    		return "";
    	}

    	for(int i = 0; i < strs[0].size(); ++i) {
    		for(int j = 1; j < strs.size(); ++j) {
    			if(strs[j].size() <= i || strs[j][i] != strs[0][i]) {  //
    				return strs[0].substr(0, i);  // return not len
    			}
    		}
		}

    	return strs[0];
    }
};

int main()
{
	vector<string> strs;
	strs.push_back("ab");
	strs.push_back("abc");
	strs.push_back("a");

	Solution slt;
	cout << slt.longestCommonPrefix(strs) << endl;

	return 0;
}

