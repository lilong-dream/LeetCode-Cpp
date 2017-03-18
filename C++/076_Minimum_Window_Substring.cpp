
// Hard

class Solution {
public:
    string minWindow(string S, string T) {
        int windowLen = INT_MAX;
		int count = 0;
		int needToFound[256] = {0};
		int tLen = T.size();
		int minWindowBegin = 0;
		for(int i = 0; i < tLen; ++i) {
			needToFound[T[i]]++;
		}

		int hasFound[256] = {0};
		for(int begin = 0, end = 0; end < S.size(); ++end) {
			if(needToFound[S[end]] == 0) {
				continue;
			}
			hasFound[S[end]]++;
			if(hasFound[S[end]] <= needToFound[S[end]]) {
				++count;
			}
			if(count == tLen) {
				while(needToFound[S[begin]] == 0 || 
					hasFound[S[begin]] > needToFound[S[begin]]) {
					if(hasFound[S[begin]] > needToFound[S[begin]]) {
						hasFound[S[begin]]--;
					}
					++begin;
				}
				if(end - begin + 1 < windowLen) {
					minWindowBegin = begin;
					windowLen = end - begin + 1;
				}
			}	 
		}

		return count == tLen ? S.substr(minWindowBegin, windowLen) : "";
    }
};

