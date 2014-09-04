// https://oj.leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        string longer, shorter;
        if(a.size() > b.size())
        {
            longer = a;
            shorter = b;
        }
        else
        {
            longer = b;
            shorter = a;
        }
        
        int m = longer.size();
        int n = shorter.size();
        
        vector<char> v(m, '0');
        
        char carry = '0';
        
        for(int i = 1; i <= n; ++i)
        {
            if(longer[m - i] == '1' && shorter[n - i] == '1')
            {
                v[m - i] = carry;
                carry = '1';
            }
            else if(longer[m - i] == '0' && shorter[n - i] == '0') 
            {
                v[m - i] = carry;
                carry = '0';
            }
            else
            {
                if(carry == '1')
                {
                    v[m - i] = '0';
                }
                else
                {
                    v[m - i] = '1';
                }
            }
        }
        
        for(int i = m - n - 1; i >= 0; --i)
        {
            if(longer[i] == '1')
            {
                if(carry == '1')
                {
                    v[i] = '0';
                }
                else
                {
                    v[i] = '1';
                }
            }
            else
            {
                v[i] = carry;
                carry = '0';
            }
        }
        
        if(carry == '1')  // !
        {
            v.insert(v.begin(), '1');
        }
        
        return string(v.begin(), v.end());
    }
};
