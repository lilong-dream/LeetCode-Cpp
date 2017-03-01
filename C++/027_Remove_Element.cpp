
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[j++] = nums[i]; 
            }
        }
        return j;
    }
};


class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int index = 0;
        for(int i = 0; i < n; ++i)
        {
            if(A[i] != elem)
            {
                A[index++] = A[i];
            }
        }
        return index;
    }
};

