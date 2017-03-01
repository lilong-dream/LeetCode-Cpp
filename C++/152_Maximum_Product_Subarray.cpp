
class Solution {
public:
    int maxProduct(int A[], int n) {
        vector<int> max(n, 0);
        max[0] = A[0];
        vector<int> min(n, 0);
        min[0] = A[0];
        
        int maxRes = max[0];
        
        for(int i = 1; i < n; ++i)
        {
            max[i] = maxOfThree(A[i], max[i - 1] * A[i], min[i - 1] * A[i]);
            maxRes = std::max(maxRes, max[i]);
            min[i] = minOfThree(A[i], max[i - 1] * A[i], min[i - 1] * A[i]);
        }
        
        return maxRes;
    }
    
    int maxOfThree(int a, int b, int c)
    {
        int tmp = std::max(a, b);
        return std::max(tmp, c);
    }
    
    int minOfThree(int a, int b, int c)
    {
        int tmp = std::min(a, b);
        return std::min(tmp, c);
    }
};


class Solution {
public:
    int maxProduct(int A[], int n) {
        vector<int> max(n, 0);
        vector<int> min(n, 0);
        max[0] = min[0] = A[0];
        int result = max[0];
        for(int i = 1; i < n; ++i)
        {
            max[i] = std::max(max[i - 1] * A[i], min[i - 1] * A[i]);
            max[i] = std::max(max[i], A[i]);
            result = std::max(result, max[i]);
            min[i] = std::min(max[i - 1] * A[i], min[i - 1] * A[i]);
            min[i] = std::min(min[i], A[i]);
        }
        return result;
    }
};

