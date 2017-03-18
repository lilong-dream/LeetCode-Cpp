// https://oj.leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while(i >= 0 && j >= 0) {
            if(A[i] > B[j]) {
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        }
        
        while(j >= 0) {
            A[k--] = B[j--];
        }
    }
};


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	if(n == 0)
    	{
    		return;
    	}

    	int idx = m + n - 1;
    	int i = m - 1;
    	int j = n - 1;

    	while(i >= 0 && j >= 0)
    	{
    		if(A[i] >= B[j])
    		{
    			A[idx--] = A[i--];
    		}
    		else
    		{
    			A[idx--] = B[j--];
    		}
    	}

    	if(i == -1)
    	{
    		while(j >= 0)
    		{
    			A[j] = B[j];
    			j--;
    		}
    	}
    }
};

