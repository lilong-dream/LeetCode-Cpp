// https://oj.leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0)
       {
           return false;
       }
       
       int div = 1;
       while(x / div >= 10)
       {
           div *= 10;
       }
       
       while(x > 0)
       {
           int l = x / div;
           int r = x % 10;
           if(l != r)
           {
               return false;
           }
           
           x = (x % div) / 10;
           div /= 100;
       }
       
       return true;
    }
};


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int d = x;
        int m = 1;
        while(d / 10) {
            m *= 10;
            d /= 10;
        }
        while(m >= 10) {
            if(x / m != x % 10) {
                return false;
            }
            x = x % m / 10;
            m /= 100;
        }
        return true;
    }
};

