
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> bits(32, 0);
        int i = 0;
        while(n) {
            bits[i++] = n % 2;
            n /= 2;
        }
        
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res = res * 2 + bits[i];
        }
        return res;
    }
};

