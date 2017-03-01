
class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0;
        int lower = 0;
        for(char ch : word) {
            if(ch >= 'a' && ch <= 'z') {
                lower++;
            } else if(ch >= 'A' && ch <= 'Z') {
                upper++;
            }
        }
        if(upper == word.size() || lower == word.size()) {
            return true;
        }
        if(lower == word.size() - 1 && word[0] >= 'A' && word[0] <= 'Z') {
            return true;
        }
        return false;
    }
};

