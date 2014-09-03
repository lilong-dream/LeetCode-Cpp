// https://oj.leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        int p = 1;
        int q = 1;
        
        for(int i = 1; i < n; ++i)
        {
            int m = q;
            q = p + q;
            p = m;
        }
        
        return q;
    }
};
