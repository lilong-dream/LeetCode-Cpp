
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        std::queue<string> q;
        std::queue<int> level;
        q.push(start);
        level.push(1);
        
        while(!q.empty()) {
            string str = q.front();
            q.pop();
            int lv = level.front();
            level.pop();
            
            for(int i = 0; i < str.size(); ++i) {
                char origChar = str[i];
                for(char ch = 'a'; ch <= 'z'; ++ch) {
                    if(ch == str[i]) {
                        continue;
                    }
                    str[i] = ch;
                    if(str == end) {
                        return lv + 1;
                    }
                    if(dict.find(str) != dict.end()) {
                        q.push(str);
                        level.push(lv + 1);
                        dict.erase(str);  // !
                    }
                }
                str[i] = origChar;
            }
        }
        
        return 0;
    }
};


class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
	    int res = 1;

		std::queue<string> q;
		q.push(start);
		q.push("");
		while(!q.empty()) {
			string curr = q.front();
			q.pop();

			if(curr != "") {
				for(int i = 0 ; i < curr.length(); ++i) {  // ?
					char tmp = curr[i];

					for(char ch = 'a'; ch <= 'z'; ++ch) {
						if(ch == tmp) {
							continue;
						}

						curr[i] = ch;

						if(curr == end) {
							return res + 1;
						}

						if(dict.find(curr) != dict.end())
						{
							q.push(curr);
							dict.erase(curr);
						}
					}
					
					curr[i] = tmp;
				}
			} else if(!q.empty()) {
				++res;
				q.push("");
			}
		}

		return 0;
    }
};

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
		if(dict.size() == 0 || start == end) {
			return 0;
		}

		std::queue<string> wq;
		std::queue<int> lq;
		wq.push(start);
		lq.push(1);

		while(!wq.empty())
		{
			string curWord = wq.front();
			wq.pop();
			int curLen = lq.front();
			lq.pop();

			for(int i = 0; i < curWord.length(); ++i)
			{
				char tmp = curWord[i];
				for(char c = 'a'; c <= 'z'; ++c)
				{
					if(c == tmp) 
					{
						continue;
					}
					curWord[i] = c;
					if(curWord == end)
						return curLen + 1; 
					if(dict.find(curWord) != dict.end())
					{
						wq.push(curWord);
						lq.push(curLen + 1);
						dict.erase(curWord); 
					}
				}
				curWord[i] = tmp;
			}
		}

		return 0;
    }
};

