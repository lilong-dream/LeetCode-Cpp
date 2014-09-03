// https://oj.leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.size() < 2)
        {
            return num.size();    
        }
        
        std::unordered_set<int> s;
        
        int longest = 0;
        
        for(int i = 0; i < num.size(); ++i)
        {
            s.insert(num[i]);
        }
        
        for(int i = 0; i < num.size(); ++i)
        {
            if(s.count(num[i]) > 0)
            {
                int count = 1;
                s.erase(num[i]);
                
                int n = num[i] - 1;
                while(s.find(n) != s.end())
                {
                    ++count;
                    s.erase(n);
                    --n;
                }
                
                n = num[i] + 1;
                while(s.find(n) != s.end())
                {
                    ++count;
                    s.erase(n);
                    ++n;
                }
                
                if(count > longest)
                {
                    longest = count;
                }
            }
        }
        
        return longest;
    }
};
