
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
	bool cmp(Interval a, Interval b) {
		return a.start < b.start;
	}
	
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() < 2) {
			return intervals;
		}
		
		std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
        	return a.start < b.start;   
    	});
		
		vector<Interval> res;
		
		Interval pre = intervals[0];
		for(int i = 1; i < intervals.size(); ++i) {
			Interval curr = intervals[i];
			
			if(pre.end >= curr.start) {
				Interval merged(pre.start, std::max(pre.end, curr.end));
				pre = merged;
			} else {
				res.push_back(pre);
				pre = curr;
			}
		}
		
		res.push_back(pre);
			
		return res;
    }
};

