// https://oj.leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) {
            return true;
        }
        
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j) {
            while(i < j && !helper(s[i])) {
                ++i;
            }
            while(i < j && !helper(s[j])) {
                --j;
            }
            
            if(i < j && s[i] != s[j]) {  //
                return false;
            }
            
            ++i;
            --j;
        }
        
        return true;
    }
    
    bool helper(char &c)  // isLetter
    {
        if(c >= '0' && c <= '9' || c >= 'a' && c <= 'z')
        {
            return true;
        }
        
        if(c >= 'A' && c <= 'Z')
        {
            c += 32;
            return true;
        }
        
        return false;
    }
};

