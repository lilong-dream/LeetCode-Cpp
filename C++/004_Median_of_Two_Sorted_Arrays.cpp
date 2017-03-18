
// Hard

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
    	int total = m + n;
    	if(total & 0x01) {
    		return find_kth(A, m, B, n, total / 2 + 1);
    	}
    	else {
    		return (find_kth(A, m, B, n, total / 2) +
    				find_kth(A, m, B, n, total / 2 + 1)) / 2.0;
    	}
    }

    double find_kth(int A[], int m, int B[], int n, int k)
    {
    	if(m > n) {
    		return find_kth(B, n, A, m, k);
    	}
    	if(m == 0) {
    		return B[k - 1];
    	}
    	if(k == 1) {
    		return std::min(A[0], B[0]);
    	}

    	int pa = std::min(k / 2, m);
    	int pb = k - pa;
    	if(A[pa - 1] < B[pb - 1]) {
    		return find_kth(A + pa, m - pa, B, n, k - pa);
    	}
    	else if(A[pa - 1] > B[pb - 1]) {
    		return find_kth(A, m, B + pb, n - pb, k - pb);
    	}
    	else {
    		return A[pa - 1];
    	}
    }
};


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if((m + n) % 2 == 0) {
            return (findK(nums1, nums2, 0, 0, (m + n) / 2) + findK(nums1, nums2, 0, 0, (m + n) / 2 + 1)) / 2.0;
        } else {
            return findK(nums1, nums2, 0, 0, (m + n) / 2 + 1);
        }
        
    }
    
    int findK(vector<int>& nums1, vector<int>& nums2, int m, int n, int k) {
        if(nums1.size() - m > nums2.size() - n) {
            return findK(nums2, nums1, n, m, k);
        }
        if(m == nums1.size()) {
            return nums2[n + k - 1];
        }
        if(k == 1) {
            return std::min(nums1[m], nums2[n]);
        }
        int x = std::min((int)(nums1.size() - m), k / 2);
        int y = k - x;
        if(nums1[m + x - 1] > nums2[n + y - 1]) {
            return findK(nums1, nums2, m, n + y, k - y);
        } else if(nums1[m + x - 1] < nums2[n + y - 1]) {
            return findK(nums1, nums2, m + x, n, k - x);
        } else {
            return nums1[m + x - 1];
        }
    }
};

