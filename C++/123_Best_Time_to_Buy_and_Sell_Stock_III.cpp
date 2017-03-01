
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
		if(len < 2)
		{
			return 0;
		}
		
		vector<int> maxleft(len, 0);
		int minprice = prices[0];
		for(int i = 1; i < len; ++i)
		{
			minprice = std::min(minprice, prices[i]); // order
			maxleft[i] = std::max(prices[i] - minprice, maxleft[i - 1]);
			
		}

		vector<int> maxright(len, 0);
		int maxprice = prices[len - 1];
		for(int i = len - 2; i >= 0; --i)
		{
			maxprice = std::max(maxprice, prices[i]);
			maxright[i] = std::max(maxprice - prices[i], maxright[i]);
			
		}

		int res = 0;
		for(int i = 0; i < len; ++i)
		{
			if(maxleft[i] + maxright[i] > res)
			{
				res = maxleft[i] + maxright[i];
			}
		}

		return res;
    }
};

