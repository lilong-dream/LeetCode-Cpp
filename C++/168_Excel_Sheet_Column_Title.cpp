
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n) {
            res = (char)('A' + (n - 1) % 26) + res;  // not to_string          
            n = (n - 1) / 26;
        }
        return res;
    }
};

