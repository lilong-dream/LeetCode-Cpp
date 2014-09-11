// https://oj.leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        
        if(num.size() < 3)
        {
            return res;
        }
        
        std::sort(num.begin(), num.end());
        
        vector<int> cur;
        
        for(int i = 0; i < num.size() - 2; ++i)
        {
            if(i > 0 && num[i] == num[i - 1])
            {
                continue;    
            }
            
            int j = i + 1;
            int k = num.size() - 1;
            
            while(j < k)
            {
                if(num[i] + num[j] + num[k] == 0)
                {
                    cur.clear();
                    cur.push_back(num[i]);
                    cur.push_back(num[j]);
                    cur.push_back(num[k]);
                    
                    res.push_back(cur);
                    
                    --k;
                    ++j;
                    
                    while(j < k && num[j] == num[j - 1])
                    {
                        ++j;
                    }
                    while(j < k && num[k] == num[k + 1])
                    {
                        --k;
                    }
                }
                else if(num[i] + num[j] + num[k] > 0)
                {
                    --k;
                }
                else
                {
                    ++j;
                }
            }
        }
        
        return res;
    }
};
