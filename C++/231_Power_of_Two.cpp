
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) {
            return false;
        }
        int m = log10(n) / log10(2);
        if(n == pow(2, m)) {
            return true;
        }
        return false;
    }
};

