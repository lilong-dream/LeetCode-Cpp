
string getRange(int lower, int upper) {
    if(lower == upper) {
        return to_string(lower);
    }
    return to_string(lower) + "->" + to_string(upper);
}

vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
    vector<string> res;
    
    for(int i = 0; i < n; i++) {
        if(A[i] - lower >= 1) {
            res.push_back(getRange(lower, A[i] - 1));
        }
        lower = A[i] + 1;
    }
    if(lower <= upper) {
        res.push_back(getRange(lower, upper));
    }
    
    return res;
}


// http://www.cnblogs.com/yrbbest/p/4489723.html 

public class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> res = new ArrayList<>();
        if (nums == null || lower > upper) return res;
        for (int num : nums) {
            if (num - lower >= 1) res.add(getRangeString(lower, num - 1));
            lower = num + 1;
        }
        if (lower <= upper) res.add(getRangeString(lower, upper));
        return res;
    }
    
    private String getRangeString(int lower, int upper) {
        if (lower == upper) return String.valueOf(lower);
        StringBuilder sb = new StringBuilder();
        sb.append(lower).append("->").append(upper);
        return sb.toString();
    }
}

