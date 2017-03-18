
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        const int m = board.size();
		const int n = board[0].size();
		vector<vector<bool> > visited(m, vector<bool>(n, false));
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(dfs(board, word, visited, 0, i, j)) {
					return true;
				}
			}
		}

		return false;
	}

	bool dfs(vector<vector<char> > &board, const string& word, vector<vector<bool> > &visited, int index, int x, int y) {
		if(index == word.size()) {
			return true;
		}

		if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
			return false;
		}

		if(visited[x][y]) {
			return false;
		}

		if(board[x][y] != word[index]) {
			return false;
		}

		visited[x][y] = true;
		bool ret = dfs(board, word, visited, index + 1, x - 1, y) ||
			dfs(board, word, visited, index + 1, x + 1, y) ||
			dfs(board, word, visited, index + 1, x, y - 1) ||
			dfs(board, word, visited, index + 1, x, y + 1);
		visited[x][y] = false;
		return ret;
	}
};

