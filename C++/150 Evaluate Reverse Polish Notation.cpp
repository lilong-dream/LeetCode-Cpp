// https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        std::stack<int> st;
        
        if(tokens.size() == 0)  
        {
            return 0;
        }
        
        for(string str : tokens)
        {
            if((str == "+") || (str == "-") || (str == "*") || (str == "/"))
            {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                
                if(str == "+")
                {
                    st.push(op1 + op2);
                }
                else if(str == "-")
                {
                    st.push(op1 - op2);
                }
                else if(str == "*")
                {
                    st.push(op1 * op2);
                }
                else
                {
                    st.push(op1 / op2);  // op2 == 0?
                }
            }
            else
            {
                st.push(atoi(str.c_str()));
            }
        }
        
        return st.top();
    }
};
