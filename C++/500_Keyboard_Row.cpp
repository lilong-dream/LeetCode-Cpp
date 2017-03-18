
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        
        map<char, int> m;
        for(char ch : "qwertyuiop") {
            m[ch] = 0;
        }
        
        for(char ch : "asdfghjkl") {
            m[ch] = 1;
        }
        
        for(char ch : "zxcvbnm") {
            m[ch] = 2;
        }
        
        
        for(string word : words) {
            int flag = -1;
            for(char ch : word) {
                if(ch < 'a') {
                    ch += 32;
                }
                if(flag == -1) {
                    flag = m[ch];
                } else {
                    if(m[ch] != flag) {
                        flag = -2;
                        break;
                    }
                }
            }
            if(flag != -2) {
                res.push_back(word);
            }
        }
        
        return res;
    }
};

