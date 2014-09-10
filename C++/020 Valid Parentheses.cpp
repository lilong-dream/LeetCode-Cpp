// https://oj.leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
        {
            return true;
        }
        
        std::stack<char> st;
        
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else 
            {
                if(st.empty() || !match(st.top(), s[i]))  // order matters!
                {
                    return false;
                }
                st.pop();
            }
        }
        
        return st.empty() ? true : false;
    }
    
    bool match(char ch1, char ch2)
    {
        if(ch1 == '(' && ch2 == ')')
        {
            return true;
        }
        else if(ch1 == '[' && ch2 == ']')
        {
            return true;
        }
        else if(ch1 == '{' && ch2 == '}')
        {
            return true;
        }
        
        return false;
    }
};
