
class Solution {
public:
    bool search(int A[], int n, int target) {
        if(n < 1) {
			return false;
		}

		int left = 0; 
		int right = n - 1;
		while(left <= right) {
			int mid = left + (right - left) / 2;
			if(A[mid] == target) {
				return true;
			} else if(A[mid] > A[left]) {
				if(A[mid] > target && target >= A[left]) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			} else if(A[mid] < A[left]) {
				if(A[mid] < target && target <= A[right]) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			} else {
				++left;
			}
		}

		return false;
    }
};

