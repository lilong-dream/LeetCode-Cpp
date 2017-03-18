
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            int n = s[i] - 'A' + 1;
            res = res * 26 + n;
        }
        return res;
    }
};

