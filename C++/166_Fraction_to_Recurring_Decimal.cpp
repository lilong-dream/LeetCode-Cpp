
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) {  //
            return "0";
        }
        
        string res;
        
        map<long, int> m;
        
        if(numerator < 0 ^ denominator < 0) {
            res += '-';
        }
        
        //uint num = abs(numerator);  // abs not ok
        long num = numerator < 0 ? (long)numerator * (-1) : (long)numerator;  //
        long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;
        
        res += to_string(num / denom);
        
        num = num % denom;
        
        if(num == 0) {
            return res;
        }
        
        res += ".";
        
        int idx = res.size();  //
        
        while(num) {
            if(m.find(num) != m.end()) {
                res += ')';
                res.insert(res.begin() + m[num], '(');
                break;  //
            }
            m[num] = idx++;
            num *= 10;
            res += to_string(num / denom);
            num = num % denom;
        }
        
        return res;
    }
};

