
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string str(s);
    	int i = str.length() - 1;

    	while(i >= 0 && str[i] == ' ') {
    		--i;
    	}

    	int length = 0;
    	while(i >= 0 && str[i] != ' ') {
    		++length;
    		--i;
    	}

    	return length;
    }
};

