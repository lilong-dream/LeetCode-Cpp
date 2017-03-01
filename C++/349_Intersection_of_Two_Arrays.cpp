
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        
        std::set<int> s1(nums1.begin(), nums1.end());
        std::set<int> s2(nums2.begin(), nums2.end());
        
        for(auto it = s1.begin(); it != s1.end(); it++) {
            auto idx = s2.find(*it);
            if(idx != s2.end()) {
                res.push_back(*it);
            }
        }
        
        return res;
    }
};


class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        s1 = set(nums1)
        s2 = set(nums2)
        res = []
        for item in s2:
            if item in s1:
                res.append(item)
        return res

func intersection(nums1 []int, nums2 []int) []int {
    res := []int{}
    s1 := map[int]bool {}
    for _, item := range nums1 {
        s1[item] = true
    }
    s2 := map[int]bool {}
    for _, item := range nums2 {
        s2[item] = true
    }
    for k := range s1 {
        if s2[k] {
            res = append(res, k)
        }
    }
    return res
}

