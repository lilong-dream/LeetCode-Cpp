
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int res = -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

