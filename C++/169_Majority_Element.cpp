
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int cnt = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == num) {
                cnt++;
            } else {
                cnt--;
                if(cnt == 0) {
                    num = nums[i];
                    cnt = 1;
                }
            }
        }
        return num;
    }
};

