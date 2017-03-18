
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty() || prices.size() == 1) {
			return 0;
		}

		int max = 0;
   
		for(int i = 1; i < prices.size(); ++i) {
			int diff = prices[i] - prices[i - 1];
			if(diff > 0) {
				max += diff;
			}
		}

		return max;
    }
};

