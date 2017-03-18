// '.' Matches any single character.
// '*' Matches zero or more of the preceding element. 

// The matching should cover the entire input string (not partial). 

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true

// Hard
// TODO

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
    
    bool isMatch(const string& s, int i, const string& p, int j) {
        if (i == s.length()) {
            return j == p.length()
                    || (p.length() > j + 1 && p[j + 1] == '*' && isMatch(s, i, p, j + 2));
        }
        
        if (p.length() > j + 1 && p[j + 1] == '*') {
            if (s[i] == p[j] || p[j] == '.') {
                return isMatch(s, i + 1, p, j) || isMatch(s, i, p, j + 2);
            } else {
                return isMatch(s, i, p, j + 2);
            }
        } else {
            if (s[i] == p[j] || p[j] == '.') {
                return isMatch(s, i + 1, p, j + 1);
            } else {
                return false;
            }
        }
    }
};


class Solution {
public:
    bool isMatch(const char *s, const char *p) {
	  assert(s && p);
	  if (*p == '\0') return *s == '\0';
	 
	  // next char is not '*': must match current character
	  if (*(p + 1) != '*') {
		assert(*p != '*');
		return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
	  }
	  // next char is '*'
	  while ((*p == *s) || (*p == '.' && *s != '\0')) {
		if (isMatch(s, p + 2)) return true;
		s++;
	  }
	  return isMatch(s, p + 2);
    }
};

