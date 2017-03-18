
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
		string ip;
		dfs(s, 0, 0, ip, res);
		return res;
    }
	
	void dfs(string s, int start, int step, string ip, vector<string> &res) {
		if(start == s.size() && step == 4) {
			ip.resize(ip.size() - 1);  // 
			res.push_back(ip);
			return;
		}

		if((s.size() - start) > (4 - step) * 3) {
			return;
		}
		if((s.size() - start) < (4 - step)) {
			return;
		}

		int num = 0;
		for(int i = start; i < start + 3; ++i) {
			num = num * 10 + (s[i] - '0');
			if(num < 256) {
				ip += s[i];
				dfs(s, i + 1, step + 1, ip + '.', res);
			}
			if(num == 0) {
				break;
			}
		}
    }
};

