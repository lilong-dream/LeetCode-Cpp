
// TODO
// DP

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        
        vector<int> vec(n, 1);
        int res = 1;
        
        for(int i = 1; i < n; i++) {
            vec[i] = 1;  //
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    vec[i] = max(vec[i], vec[j] + 1);
                }
            }
            res = max(res, vec[i]);  //
        }
        return res;
    }
};

