
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            res++;
            n &= (n - 1);
        }
        return res;
    }
};


class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0) {
            return 0;
        }
        int res = 0;
        while(n ^ (n - 1)) {
            res++;
            n = n & (n - 1);
            if(n == 0) {
                break;
            }
        }
        return res;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0) {
            return 0;
        }
        int res = 0;
        while(n ^ (n - 1)) {
            res++;
            n = n & (n - 1);
            if(n == 0) {
                break;
            }
        }
        return res;
    }
};

class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
        res = 0
        while n ^ (n - 1):
            res += 1
            n = n & (n - 1)
            if n == 0:
                break
        return res

