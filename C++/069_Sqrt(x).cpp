// https://oj.leetcode.com/problems/sqrtx/

class Solution {
public:
    int sqrt(int x) {
        if(x < 2)
        {
            return x;
        }
        
        int left = 1, right = x / 2;
        
        int last = 0;
        
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if(x / mid > mid)
            {
                left = mid + 1;
                last = mid;
            }
            else if(x / mid < mid)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        
        return last;
    }
};

