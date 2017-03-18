
// Hard

class Solution {
public:
    int trap(int A[], int n) {
        if(n < 3)
		{
			return 0;
		}

		int maxleft = 0;
		int *maxl = new int[n]();
		
		for(int i = 0; i < n; ++i)
		{
			maxl[i] = maxleft;
			if(A[i] > maxleft)
			{
				maxleft = A[i];
			}
		}

		int res = 0;
		int maxright = 0;
		int *maxr = new int[n]();
		for(int i = n - 1; i >= 0; --i)
		{
			maxr[i] = maxright;
			if(A[i] > maxright)
			{
				maxright = A[i];
			}

			int cur = std::min(maxl[i], maxr[i]) - A[i];
			if(cur > 0)
			{
				res += cur;
			}
		}

		delete[] maxl;
		delete[] maxr;

		return res;
    }
};

