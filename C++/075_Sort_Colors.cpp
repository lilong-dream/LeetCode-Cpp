
// from leetcode solution 

class Solution {
public:
	void sortColors(int A[], int n) {
		int second = n - 1, zero = 0;
		for (int i = 0; i <= second; i++) {
			while (A[i] == 2 && i < second) swap(A[i], A[second--]);
			while (A[i] == 0 && i > zero) swap(A[i], A[zero++]);
		}
	}
};


// two pass O(m+n) space
void sortColors(int A[], int n) {
    int num0 = 0, num1 = 0, num2 = 0;
    
    for(int i = 0; i < n; i++) {
        if (A[i] == 0) ++num0;
        else if (A[i] == 1) ++num1;
        else if (A[i] == 2) ++num2;
    }
    
    for(int i = 0; i < num0; ++i) A[i] = 0;
    for(int i = 0; i < num1; ++i) A[num0 + i] = 1;
    for(int i = 0; i < num2; ++i) A[num0 + num1 + i] = 2;
}

// one pass in place solution
void sortColors(int A[], int n) {
    int j = 0, k = n - 1;
    for (int i = 0; i <= k; ++i){
        if (A[i] == 0 && i != j)
            swap(A[i--], A[j++]);
        else if (A[i] == 2 && i != k)
            swap(A[i--], A[k--]);
    }
}

