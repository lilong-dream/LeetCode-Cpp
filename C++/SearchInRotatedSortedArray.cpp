// Problem:  http://oj.leetcode.com/problems/search-in-rotated-sorted-array/
// Analysis: http://blog.csdn.net/lilong_dream/article/details/22864861
// 1988lilong@163.com

#include <iostream>

class Solution {
public:
    int search(int A[], int n, int target) {
    	int left = 0;
    	int right = n - 1;

    	while(left <= right)
    	{
    		int mid = (left + right) / 2;

    		if(A[mid] == target)
    		{
    			return mid;
    		}

    		if(A[mid] >= A[left])
    		{
    			if(A[mid] > target && A[left] <= target)
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
    		}
    		else
    		{
    			if(A[mid] < target && A[right] >= target)
    			{
    				left = mid + 1;
    			}
    			else
    			{
    				right = mid - 1;
    			}
    		}
    	}

    	return -1;
    }
};

int main()
{
	int A[] = {4, 5, 6, 7, 0, 1, 2};

	Solution slt;
	std::cout << slt.search(A, 7, 1) << std::endl;
	std::cout << slt.search(A, 7, 8) << std::endl;

	return 0;
}
