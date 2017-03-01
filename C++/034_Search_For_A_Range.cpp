// Problem:  http://oj.leetcode.com/problems/search-for-a-range/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/22893675
// 1988lilong@163.com

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
    	int left = 0;
    	int right = n - 1;

    	vector<int> result;
    	result.push_back(-1);
    	result.push_back(-1);

    	while(left <= right)
    	{
    		int mid = (left + right) / 2;

    		if(A[mid] > target)
    		{
    			right = mid - 1;
    		}
    		else if(A[mid] < target)
    		{
    			left = mid + 1;
    		}
    		else
    		{
    			result[0] = mid;
    			result[1] = mid;

    			int j = mid - 1;
    			while(j >= 0 && A[j] == target)
    			{
    				result[0] = j;
    				j--;
    			}

    			j = mid + 1;
    			while(j < n && A[j] == target)
    			{
    				result[1] = j;
    				j++;
    			}

    			break;
    		}
    	}

    	return result;
    }
};

int main()
{
	int A[] = {1, 2, 4, 4, 5};

	Solution slt;
	vector<int> result = slt.searchRange(A, 5, 4);
	std::cout << result[0] << " " << result[1] << std::endl;
}

