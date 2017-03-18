
// Hard

class Solution {
public:
    int longestValidParentheses(string s) {
		const char* str = s.c_str();  
	    int nMax = 0;  
		const char *p = str;  
		vector<const char*> sta;  
	    while(*p !='\0')  
	    {  
			if(*p == '(')  
			{  
				sta.push_back(p);                      
			}  
			else  
			{  
				if(!sta.empty() && *sta.back() == '(')  // 
				{  
					sta.pop_back();  
				    nMax = max(nMax, p - (sta.empty() ? str - 1 : sta.back()));  
				}  
				else  
			    {  
				    sta.push_back(p);  
				}  
			}  
			p++;  
		}  
		return nMax;  
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        std::stack<int> st;
        int last = -1;  // 
        int max = 0;
        int cur = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if(st.empty())
                {
                    last = i;
                }
                else
                {
					st.pop();
					if(st.empty())
					{
						cur = i - last;
					}
					else
					{
						cur = i - st.top();
					}
					if(cur > max)
					{
						max = cur;
					}
                }
            }
        }

        return max;
    }
};

