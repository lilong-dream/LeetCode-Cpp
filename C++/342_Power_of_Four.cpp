
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 0) {
            return false;
        }
        int n = log10(num) / log10(4);
        if(num == pow(4, n)) {
            return true;
        }
        return false;
    }
};

