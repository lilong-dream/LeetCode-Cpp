
// Rotate an array of n elements to the right by k steps.
// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;  //
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
    
    void reverse(vector<int>& nums, int begin, int end) {
        while(begin < end) {
            int tmp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = tmp;
            begin++;
            end--;
        }
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        int i = 0;
        int end = 0;
        int num = nums[0];
        int cnt = 0;  // 记录处理的个数
        
        while(true) {  // 直接n次也行, k,n最大公约数结束更佳; 循环交换亦可
            int j = (i - k + n) % n;

            if(j == end) {
                nums[i] = num;
                cnt++;
                if(cnt == n) {  
                    break;
                }
                
                i = (end + 1) % n;  // 
                end = i;         
                num = nums[i];
            } else {
                nums[i] = nums[j];
                i = j;
                cnt++;
            }
        }
    }
};

