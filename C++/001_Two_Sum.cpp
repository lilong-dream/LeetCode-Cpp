// https://oj.leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::unordered_map<int, int> m;
        
        vector<int> res;
        
        for(int i = 0; i < numbers.size(); ++i)
        {
            if(m.find(target - numbers[i]) != m.end())
            {
                res.push_back(m[target - numbers[i]]);
                res.push_back(i);
                break;
            }
            else
            {
                m[numbers[i]] = i;
            }
        }
        
        return res;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int> &num, int target) {
        unordered_map<int, int> mapping;
		vector<int> result;
		for (int i = 0; i < num.size(); i++) {
			mapping[num[i]] = i;
		}
		for (int i = 0; i < num.size(); i++) {
			const int gap = target - num[i];
			if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
				result.push_back(i + 1);
				result.push_back(mapping[gap] + 1);
				break;
			}
		}
		return result;
    }
};

