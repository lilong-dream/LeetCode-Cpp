// https://oj.leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 0;
        
        for(int i = digits.size() - 1; i >= 0; --i)
        {
            if(digits[i] == 9)
            {
                digits[i] = 0;
                carry = 1;
            }
            else
            {
                digits[i] += 1;
                carry = 0;
                break;
            }
        }
        
        if(carry)
        {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int j = digits.size() - 1;
        int carry = 1;
        for(; j >= 0; j--) {
            int n = digits[j] + carry;
            if(n > 9) {
                carry = 1;
                digits[j] = n % 10;
            } else {
                digits[j] = n;
                carry = 0;
                break;
            }
        }
        if(carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};

