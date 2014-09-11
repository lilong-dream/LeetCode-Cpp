// https://oj.leetcode.com/problems/implement-strstr/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!*needle)
        {
            return haystack;
        }
        
        char *advance = haystack;
        char *p = haystack;
        char *p2 = needle + 1;
        
        while(*p2)
        {
            ++advance;
            ++p2;
        }
        
        while(*advance)
        {
            char *p1 = p;
            p2 = needle;
            
            while(*p2 && *p1 == *p2)
            {
                ++p1;
                ++p2;
            }
            
            if(!*p2)
            {
                return p;
            }
            
            ++advance;
            ++p;
        }
        
        return NULL;
    }
};
