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


class Solution {
public:
    void reverseWords(string &s) {
        int i = 0;
        int j = 0;
        int cnt = 0;
        while(i < s.size()) {
            while(i < s.size() && s[i] == ' ') {
                i++;
            }
            if(i == s.size()) {
                break;
            }
            if(cnt) {
                s[j++] = ' ';
            }
            int start = j;
            while(i < s.size() && s[i] != ' ') {
                s[j++] = s[i++];
            }
            reverse(s, start, j - 1);
            cnt++;
        }
        s.resize(j);
        reverse(s, 0, j - 1);
    }

    void reverse(string &s, int left, int right) {
        while(left < right)
        {
            char ch = s[left];
            s[left++] = s[right];
            s[right--] = ch;
        }
    }
};

class Solution {
public:
    void reverseWords(string &s) {
        string str = s;
		reverse(str);
		s = "";
		int start = 0;
		while(str[start] == ' ')
		{
			++start;
		}
		int i = start;
		while(i < str.length())
		{
			while(i < str.length() && str[i] != ' ') {
				++i;
			}
			string word = str.substr(start, i - start);
			reverse(word);
			if(s.empty())
			{
				s += word;
			}
			else
			{
				s = s + " " + word;
			}
			while(i < str.length() && str[i] == ' ') {
				++i;
			}
			start = i;
		}
	}

	void reverse(string &s)
	{
		int left = 0;
		int right = s.length() - 1;
		while(left < right)
		{
			char ch = s[left];
			s[left++] = s[right];
			s[right--] = ch;
		}
    }
};

class Solution {
public:
	string helper(string &s)
	{
		int start = 0;
		int end = s.size() - 1;
		while(start < end)
		{
			char ch = s[start];
			s[start++] = s[end];
			s[end--] = ch;
		}

		return s;
    }
    
    void reverseWords(string &s) {
        int len = s.size();
        helper(s);
		string res; 

		int i = 0;
		while(i < len)
		{
			while(i < len && s[i] == ' ')  // extra space is ignorged
			{
				++i;
			}
			int begin = i;
			while(i < len && s[i] != ' ')
			{
				++i;
			}
			if(i > begin)
			{
				if(!res.empty())
				{
					res += " ";
				}
				string str = s.substr(begin, i - begin);
				helper(str);
				res += str; // pay attention to the second para!
			}
		}

		s = res;
    }
};

class Solution {
public:
    void reverseWords(string &s) {
    	string str = trim(s);
    	int index;
    	string result;
    	while((index = str.find_last_of(" ")) != string::npos)
    	{
    		result += str.substr(index + 1);
    		result += " ";
    		str = str.substr(0, index);
    		rtrim(str);
    	}

    	result += str;

    	s = result;
    }

    // trim from start
    static inline std::string &ltrim(std::string &s) {
            s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
            return s;
    }

    // trim from end
    static inline std::string &rtrim(std::string &s) {
            s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
            return s;
    }

    // trim from both ends
    static inline std::string &trim(std::string &s) {
            return ltrim(rtrim(s));
    }
};

