
// TODO

class Solution {
public:
    int singleNumber(int A[], int n) {
        int one = 0;
        int two = 0;
        int three = 0;
        
        for(int i = 0; i < n; ++i)
        {
            two |= one & A[i];
            one ^= A[i];
            three = ~(one & two);
            one &= three;
            two &= three;
        }
        return one;
    }
};


class Solution {
public:
    int singleNumber(int A[], int n) {
        int count[32] = {0};
		int result = 0;
		for (int i = 0; i < 32; ++i) {
			for (int j = 0; j < n; ++j) {
				if (((A[j] >> i) & 1) != 0) {
					count[i]++;
				}
			}
			result |= ((count[i] % 3) << i);
		}
		return result;
    }
};

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;

		for (int i = 0; i < 32; ++i) {
			int c = 0, d = 1 << i;
			for (int j = 0; j < n; ++j) {
				if ((A[j] & d) != 0) {
					c++;
				}
			}

			if ((c % 3) != 0) {
				res |= d;
			}
		}

		return res;
    }
};

