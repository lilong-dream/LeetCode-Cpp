
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
		
		helper(num, 0, res);
		
		return res;
    }
	
	void helper(vector<int>& num, int start, vector<vector<int> >& res)
	{
		if(start == num.size())
		{
			res.push_back(num);
			return;
		}
		
		for(int i = start; i < num.size(); ++i)  // not start + 1
		{
			std::swap(num[start], num[i]);
			helper(num, start + 1, res);
			std::swap(num[start], num[i]);
		}
    }
};

