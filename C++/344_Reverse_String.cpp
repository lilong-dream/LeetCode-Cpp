
class Solution {
public:
	string reverseString(string s) {
		string  str = s;
		int i = 0;
		int j = str.size() - 1;

		while(i < j)
		{
			char ch = str[i];
			str[i++] = str[j];
			str[j--] = ch;
		}

		return str;
	}
};


func reverseString(s string) string {
	chars := []rune(s) 
    for i, j := 0, len(chars) - 1; i < j; i, j = i + 1, j -1 {
		chars[i], chars[j] = chars[j], chars[i]
	} 
	return string(chars);
}

/**
 * @param {string} s
 * @return {string}
 */
var reverseString = function(s) {
    var str = '';
    var j = s.length - 1;
    while(j >= 0) {
        str += s[j]
        j -= 1;
    }
    return str;
};

class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = []
        j = len(s) - 1
        while j >= 0:
            res.append(s[j])
            j -= 1
        return ''.join(res)

