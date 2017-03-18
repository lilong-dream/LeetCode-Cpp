// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).// 

// The matching should cover the entire input string (not partial).// 

// The function prototype should be:
// bool isMatch(const char *s, const char *p)// 

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false

// Hard
// TODO

// from leetcode solution

bool isMatch(const char *s, const char *p) {
	const char* star = NULL;
	const char* ss = s;
	while (*s){
		//advancing both pointers when (both characters match) or ('?' found in pattern)
		//note that *p will not advance beyond its length 
		if ((*p == '?') || (*p == *s)) {s++; p++; continue;} 

		// * found in pattern, track index of *, only advancing pattern pointer 
		if (*p == '*') {star = p++; ss = s; continue;} 

		//current characters didn't match, last pattern pointer was *, current pattern pointer is not *
		//only advancing pattern pointer
		if (star){ p = star + 1; s = ++ss; continue;} 

	    //current pattern pointer is not star, last patter pointer was not *
	    //characters do not match
		return false;
	}

    //check for remaining characters in pattern
	while (*p == '*') {p++;}

	return !*p;  
}


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, asterisk = -1, match;
        while (i < m) {
            if (j < n && p[j] == '*') {
                match = i; 
                asterisk = j++;
            }
            else if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++; 
                j++;
            }
            else if (asterisk >= 0) {
                i = ++match;
                j = asterisk + 1;
            }
            else return false;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};

