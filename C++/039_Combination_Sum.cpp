
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());  // 剪枝
		
		vector<vector<int> > res;
		vector<int> sol;
		
		if(candidates.empty()) {
			return res;
		}
		
		helper(candidates, target, 0, sol, res);
		return res;
    }
	
	void helper(vector<int> &candidates, int target, int start, vector<int> &sol, vector<vector<int> > &res) {
		if(target == 0) {
			res.push_back(sol);
			return;
		}
		
		for(int i = start; i < candidates.size(); ++i) {
			if(target < candidates[i]) {
				return;
			}
			
			sol.push_back(candidates[i]);
			helper(candidates, target - candidates[i], i, sol, res);
			sol.pop_back();
		}
    }
};

