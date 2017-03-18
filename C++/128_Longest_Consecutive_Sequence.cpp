// https://oj.leetcode.com/problems/longest-consecutive-sequence/

// Hard

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


class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> used;
        for(int i = 0; i < num.size(); ++i)
        {
            used[num[i]] = false;
        }
        int max = 0;
        for(int i = 0; i < num.size(); ++i)
        {
            if(used[num[i]])
            {
                continue;
            }
            used[num[i]] = true;
            
            int j = num[i] + 1;
            while(used.find(j) != used.end())
            {
                used[j] = true;
                ++j;
            }
            int k = num[i] - 1;
            while(used.find(k) != used.end())
            {
                used[k] = true;
                --k;
            }
            if(j - 1 - k > max)
            {
                max = j - 1 - k;
            }
        }
        
        return max;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        std::set<int> s;
		for(int i = 0; i < num.size(); ++i)
		{
			s.insert(num[i]);
		}
		
		int max = 0;
		for(int i = 0; i < num.size(); ++i)
		{
			int left = num[i] - 1;
			int right = num[i] + 1;
			int count = 1;
			while(s.find(left) != s.end())
			{
				count++;
				s.erase(left); // 
				left--;
			}
			while(s.find(right) != s.end())
			{
				count++;
				s.erase(left); 
				right++;
			}
			if(count > max)
			{
				max = count;
			}
		}
	
		return max;
    }
};

