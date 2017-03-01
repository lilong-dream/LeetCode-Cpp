
class Solution {
public:
    void dfs(int N, int cur, vector<int> &vec, int &res) {
        if(cur == N) {
            res++;
            return;
        }
        
        for(int i = 0; i < N; i++) {  // not from cur
            if(vec[i] == 0) {
                continue;
            }
            
            if(vec[i] % (cur + 1) != 0 && (cur + 1) % vec[i] != 0) {
                continue;                
            }
            
            int tmp = vec[i];
            vec[i] = 0;
            dfs(N, cur + 1, vec, res);
            vec[i] = tmp;
        }
    }

    int countArrangement(int N) {
        vector<int> vec(N, 0);
        for(int i = 1; i <= N; ++i) {
            vec[i - 1] = i;
        }
        int res = 0;
        dfs(N, 0, vec, res);  // no &
        return res;
    }
};

