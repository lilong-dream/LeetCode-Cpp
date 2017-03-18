// https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size() - 1;
        
        if(n < 1) {  //
            return 0;
        }
        
        vector<int> p(n, 0);
        
        for(int i = 0; i < n; ++i) {
            p[i] = prices[i + 1] - prices[i];
        }
        
        int max = 0;  //
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += p[i];
            
            if(sum > max) {
                max = sum;    
            }
            
            if(sum < 0) {
                sum = 0;
            }
        }
        
        return max;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> diff;
        for(int i = 1; i < prices.size(); i++) {
            diff.push_back(prices[i] - prices[i - 1]);
        }
        int pro = 0;
        int max = 0;
        for(int i = 0; i < diff.size(); i++) {
            pro += diff[i];
            if(pro < 0) {
                pro = 0;
            }
            if(pro > max) {
                max = pro;
            }
        }
        return max;
    }
};

