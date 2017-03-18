
// Hard

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0;
        int right = num.size() - 1;
        
        while(left < right && num[left] >= num[right])
        {
            while(left < right && num[left] == num[right])
            {
                ++left;
            }
            if(left == right)
            {
                break;
            }
            int mid = left + (right - left) / 2;
            if(num[mid] > num[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return num[left];
    }
};

