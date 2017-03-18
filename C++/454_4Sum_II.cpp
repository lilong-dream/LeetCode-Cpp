
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> m;
        int res = 0;
        
        for(int num1 : A) {
            for(int num2 : B) {
                if(m.find(num1 + num2) == m.end()) {
                    m[num1 + num2] = 1;
                } else {
                    m[num1 + num2]++;
                }
            }
        }
        
        for(int num1 : C) {
            for(int num2 : D) {
                if(m.find(-(num1 + num2)) != m.end()) {
                    res += m[-(num1 + num2)];
                }
            }
        }
        
        return res;
    }
};

