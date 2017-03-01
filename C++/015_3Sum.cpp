// Problem:  http://oj.leetcode.com/problems/3sum/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/21645437
// 1988lilong@163.com

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > result;

		if(num.size() < 3)
		{
			return result;
		}

		vector<int> tmp;

		std::sort(num.begin(), num.end());

		for(int i = 0; i < num.size() - 2; ++i)
		{
			if(i > 0 && num[i] == num[i - 1])
			{
				continue;
			}

			int j = i + 1;
			int k = num.size() - 1;

			while(j < k)
			{
				if(num[i] + num[j] + num[k] > 0)
				{
					--k;
				}
				else if(num[i] + num[j] + num[k] < 0)
				{
					++j;
				}
				else
				{
					tmp.clear();
					tmp.push_back(num[i]);
					tmp.push_back(num[j]);
					tmp.push_back(num[k]);

					result.push_back(tmp);

					++j;
					--k;

					while(j < k && num[j] == num[j - 1])
					{
						++j;
					}
					while(j < k && num[k] == num[k + 1])
					{
						--k;
					}
				}
			}
		}

		return result;
	}
};

/*
int main()
{
	Solution slt;
	vector<int> num;
	num.push_back(-1);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(-1);
	num.push_back(4);

	vector<vector<int> > result = slt.threeSum(num);

	for(int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i][0] << " " << result[i][1] << " "
				  << result[i][2] << " " << std::endl;
	}

	return 0;
} */

