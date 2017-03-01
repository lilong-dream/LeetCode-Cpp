
class Solution {
public:
    bool isVowel(char ch) {
        if(ch < 'a') {
            ch += 32;
        }    
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }
    
    string reverseVowels(string s) {
        if(s.length() < 2) {
            return s;
        }
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            while(!isVowel(s[i])) {
                i++;
            }
            while(!isVowel(s[j])) {
                j--;
            }
            if(i < j) {
                char ch = s[i];
                s[i] = s[j];
                s[j] = ch;
                i++;
                j--;
            }
        }
        return s;
    }
};

