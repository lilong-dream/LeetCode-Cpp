// https://oj.leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        std::unordered_set<int> s;
        
        for(int i = 0; i < n; ++i)
        {
            if(A[i] > 0)
            {
                s.insert(A[i]);
            }
        }
        
        int num = 1;
        while(true)
        {
            if(s.find(num) != s.end())
            {
                ++num;
            }
            else
            {
                return num;
            }
        }
    }
};
