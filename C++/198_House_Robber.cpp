
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        vector<int> vec(nums.size() + 1, 0);
        vec[1] = nums[0];
        for(int i = 2; i <= nums.size(); i++) {
            vec[i] = std::max(vec[i - 1], vec[i - 2] + nums[i - 1]);
        }
        return vec[nums.size()];
    }
};

