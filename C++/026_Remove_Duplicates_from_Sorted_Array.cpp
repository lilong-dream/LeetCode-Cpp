
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int k = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != nums[k]) {
                nums[++k] = nums[i];
            }
        }
        return k + 1;
    }
};


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)
        {
            return 0;
        }
        
        int index = 0;
        for(int i = 1; i < n; ++i)
        {
            if(A[i] != A[index])
            {
                A[++index] = A[i];
            }
        }
        
        return index + 1;
    }
};

