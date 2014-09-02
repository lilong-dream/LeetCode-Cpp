// https://oj.leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    void reverseWords(string &s) {
        std::stack<string> st;
        
        int len = s.size();
        
        int i = 0;
        while(i < len)
        {
            while(i < len && s[i] == ' ')
            {
                ++i;
            }
            
            if(i == len)
            {
                break;    
            }
            
            int j = i + 1; 
        
            while(j < len && s[j] != ' ')
            {
                ++j;
            }
        
            st.push(s.substr(i, j - i));
            
            i = j + 1;
        }
        
        if(st.empty())
        {
            s = "";
            return;
        }
        
        s = st.top();
        st.pop();
        
        while(!st.empty())
        {
            s = s + ' ' + st.top();
            st.pop();
        }
    }
};
