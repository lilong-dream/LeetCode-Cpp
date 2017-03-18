
// Hard

// [-+]?(([0-9]+(.[0-9]*)?)|.[0-9]+)(e[-+]?[0-9]+)?

class Solution {
public:
    bool isNumber(const char *s) {
        // Check whether s is a valid number.

		string str(s);

		// Remove the leading and tailing spaces
		int i = 0;
		while(str[i] == ' ')
			++i;

		str = str.substr(i);

		i = str.length() - 1;
		while(str[i] == ' ') 
			--i;
		
		str = str.substr(0, i + 1);    
        
		int divPos;
        if((divPos = str.find("e")) != string::npos)
		{
            // Might be a number in scientific notation.
            return isNumberWithoutE(str.substr(0, divPos)) && isNumberWithoutE(str.substr(divPos + 1), false);
		}
        else if((divPos = str.find("E")) != string::npos)
		{
            // Might be a number in scientific notation
            return isNumberWithoutE(str.substr(0, divPos)) && isNumberWithoutE(str.substr(divPos + 1), false);
		}
        else
		{
            // Might be a number not in scientific notation
            return isNumberWithoutE(str);
		}
    }
	
	bool isNumberWithoutE(string s, bool decimalAllow = true)
	{
        // Check whether s is a number not in scientific notation

        string digits = "1234567890";
        
        int sLen = s.length();
        if(sLen == 0)
			return false;
        
        if(s[0] == '+' || s[0] == '-')
		{
            // Skip the sign
            s = s.substr(1); 
			sLen -= 1;
            if(sLen == 0)
				return false;
		}

		int decimalPoint;
        if((decimalPoint = s.find(".")) != string::npos)
        {
			if(sLen == 1 || !decimalAllow)
				return false;
            
            for(char item : s.substr(0,decimalPoint) + s.substr(decimalPoint+1))
                if(digits.find(item) == string::npos)          
					return false;
			//else
                // All elements are digits (except one decimal point)
			return true;
		}
        else
		{
            for(char item : s)
                if(digits.find(item) == string::npos)
					return false;
			//else 
                // All elements are digits
			return true;
		}
    }
};


class Solution {
public:
    bool isNumber(const char *s) {
        if (s == NULL) {
            return false;
		}
              
        while(isspace(*s)) {
        	s++;
		}
             
        if(*s == '+' || *s == '-') {
            s++;
		}
             
         bool eAppear = false;
         bool dotAppear = false;
         bool firstPart = false;
         bool secondPart = false;
         bool spaceAppear = false;
         while(*s != '\0') {
             if (*s == '.') {
                 if (dotAppear || eAppear || spaceAppear)
                     return false;
                 else
                     dotAppear = true;
             }
             else if (*s == 'e' || *s == 'E')
             {
                 if (eAppear || !firstPart || spaceAppear)
                     return false;
                 else
                     eAppear = true;
             }
             else if (isdigit(*s))
             {
                 if (spaceAppear)
                     return false;
                     
                 if (!eAppear)
                     firstPart = true;
                 else
                     secondPart = true;
             }
             else if (*s == '+' || *s == '-')
             {
                 if (spaceAppear)
                     return false;
                     
                 if (!eAppear || !(*(s-1) == 'e' || *(s-1) == 'E'))
                     return false;
             }
             else if (isspace(*s))
                 spaceAppear = true;
             else
                 return false;
                 
             s++;            
         }
         
         if (!firstPart)
             return false;
         else if (eAppear && !secondPart)
             return false;
         else
             return true;
    }
};

