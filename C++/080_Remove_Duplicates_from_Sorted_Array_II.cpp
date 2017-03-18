
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n < 3) {
			return n;
		}

		int j = 2;
		for(int i = 2; i < n; ++i) {
			if((A[i] == A[j - 1]) && (A[i] == A[j - 2])) {
				continue;
			} else {
				A[j++] = A[i]; 
			}
		}

		return j;
    }
};

