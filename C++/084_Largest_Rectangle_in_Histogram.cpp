
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        std::stack<int> s;
		int maxArea = 0; // ? 
		height.push_back(0);
		for(int i = 0; i < height.size(); )
		{
			if(s.empty() || height[i] > height[s.top()])
			{
				s.push(i++);
			}
			else
			{
				int tmp = s.top();
				s.pop();
				maxArea = std::max(maxArea, height[tmp] * (s.empty() ? i : i - s.top() - 1));
			}
		}
		
		return maxArea;
    }
};

