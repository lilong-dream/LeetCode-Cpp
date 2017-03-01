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


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        std::stack<int> st;
        for(int i = 0; i < tokens.size(); ++i)
        {
            if(tokens[i] == "+" || tokens[i] == "-"
                || tokens[i] == "*" || tokens[i] == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                if(tokens[i] == "+")
                {
                    a += b;
                }
                else if(tokens[i] == "-")
                {
                    a -= b;
                }
                else if(tokens[i] == "*")
                {
                    a *= b;
                }
                else
                {
                    a /= b;
                }
                st.push(a);
            }
            else
            {
                st.push(atoi(tokens[i].c_str()));
            }
        }
        
        return st.top();
    }
};

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
		std::stack<int> s;

		for(int i = 0; i < tokens.size(); ++i)
		{
			if(isOperator(tokens[i]))
			{
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				switch(tokens[i][0])
				{
					case '+':
						s.push(a + b);
						break;
					case '-':
						s.push(a - b);
						break;
					case '*':
						s.push(a * b);
						break;
					case '/':
						s.push(a / b);  // b == 0?
						break;
				}
			}
			else
			{
				int num = 0;
				int j = 0;
				int sign = 1;
				if(tokens[i][j] == '-')  // !
				{
					++j;
					sign = -1;
				}
				for(; j < tokens[i].size(); ++j)
				{
					num = num * 10 + (tokens[i][j] - '0');
				}
				s.push(sign * num);
			}
		}

		if(s.empty())
		{
			return 0;
		}
		else
		{
			return s.top();
		}
    }

	bool isOperator(string str)
	{
		return str == "+" || str == "-" || str == "*" || str == "/";
	}
};

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
    	std::stack<int> s;
    	string operators = "+-*/";
    	int num1 = 0;
    	int num2 = 0;

    	for(int i = 0; i < tokens.size(); ++i)
    	{
    		int pos = operators.find(tokens[i]);
    		if(pos == string::npos)
    		{
    			s.push(atoi(tokens[i].c_str()));
    		}
    		else
    		{
    			num2 = s.top();
    			s.pop();
    			num1 = s.top();
    			s.pop();

    			if(tokens[i] == "+")
    			{
    			    s.push(num1 + num2);
    			}
    			else if(tokens[i] == "-")
    			{
    				s.push(num1 - num2);
    			}
    			else if(tokens[i] == "*")
    			{
    				s.push(num1 * num2);
    			}
    			else
    			{
    				if(num2 != 0)
    				{
    					s.push(num1 / num2);
    				}
    			}
    		}
    	}

    	return s.top();
    }
};

