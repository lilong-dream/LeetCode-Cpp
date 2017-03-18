// https://oj.leetcode.com/problems/first-missing-positive/

// Hard

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        std::unordered_set<int> s;
        
        for(int i = 0; i < n; ++i)
        {
            if(A[i] > 0)
            {
                s.insert(A[i]);
            }
        }
        
        int num = 1;
        while(true)
        {
            if(s.find(num) != s.end())
            {
                ++num;
            }
            else
            {
                return num;
            }
        }
    }
};


class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        helper(A, n);

		for(int i = 0; i < n; ++i)
		{
			if(A[i] != i + 1)
			{
				return i + 1;
			}
		}

		return n + 1;
    }

	void helper(int A[], int n)
	{
		for(int i = 0; i < n; ++i)
		{
			while(A[i] != i + 1)
			{
				if(A[i] < 1 || A[i] > n || A[i] == A[A[i] - 1])
				{
					break;
				}
				std::swap(A[i], A[A[i] - 1]);
			}
		}
    }
};

