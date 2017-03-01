
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    //  if(n == 0)
    // 	{
    // 		return 0;
    // 	}

    	int left = 0;
    	int right = n - 1;
    	int mid = 0;

    	while(left <= right)
    	{
    		mid = (left + right) / 2;
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
    			return mid;
    		}
    	}

    	return left;
    }
};

