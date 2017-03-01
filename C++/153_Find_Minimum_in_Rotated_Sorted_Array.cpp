
class Solution {
public:
    int findMin(vector<int> &num) {
        // if(num.size() == 1)
        // {
        //     return num[0];
        // }
        
        int i = 0; 
        int j = num.size() - 1;
        
        while(num[i] > num[j])
        {
            int mid = i + (j - i) / 2;
            if(num[mid] > num[j])
            {
                i = mid + 1;
            }
            else
            {
                j = mid;
            }
        }
        return num[i];
    }
};

