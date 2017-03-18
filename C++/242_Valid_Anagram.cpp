
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        int n[26] = {0};  //
        for(char ch : s) {
            n[ch - 'a']++;
        }
        for(char ch : t) {
            n[ch - 'a']--;
            if(n[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        map<char, int> m;
        for(char ch : s) {
            if(m.find(ch) == m.end()) {
                m[ch] = 1;
            } else {
                m[ch]++;
            }
        }
        for(char ch : t) {
            if(m.find(ch) == m.end()) {
                return false;
            }
            m[ch]--;
            if(m[ch] < 0) {
                return false;
            }
        }
        return true;
    }
};

