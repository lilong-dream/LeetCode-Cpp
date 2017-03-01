
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
       	if(num.size() < 3)
		{
			return 0;
		}

		std::sort(num.begin(), num.end());

		int min_gap = INT_MAX;
		int res = INT_MAX;

		for(int i = 0; i < num.size() - 2; ++i)
		{
			int j = i + 1;
			int k = num.size() - 1;
			while(j < k)
			{
				int sum = num[i] + num[j] + num[k];
				if(sum == target)
				{
					return sum;
				}
				int cur_gap = std::abs(sum - target);
				if(cur_gap < min_gap)
				{
					min_gap = cur_gap;
					res = sum;
				}
				if(sum < target)
				{
					++j;
				}
				else
				{
					--k;
				}
			}
		}

		return res;
    }
};

