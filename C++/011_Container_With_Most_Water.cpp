
class Solution {
public:
    int maxArea(vector<int> &height) {
        int start = 0; 
		int end = height.size() - 1;
		int res = INT_MIN;

		while(start < end) {
			int cur = std::min(height[start], height[end]) * (end - start);
			res = std::max(res, cur);
			if(height[start] <= height[end]) {
				++start;
			}
			else {
				--end;
			}
		}

		return res;
    }
};

