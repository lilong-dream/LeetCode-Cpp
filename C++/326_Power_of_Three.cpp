
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) {
            return false;
        }
        int m = log10(n) / log10(3);
        if(n == pow(3, m)) {
            return true;
        }
        return false;
    }
};

