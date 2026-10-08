class Solution {
private:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int n){
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return false;// check boundary
        char letter = board[r][c];
        if(letter == '#' || letter != word[n]) return false; // otherwise the letter matches
        if(n == word.length() - 1) return true; // following the last line
        board[r][c] = '#';
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i < 4; i++){
            int rr = r + dir[i][0], cc = c + dir[i][1];
            if(dfs(board, word, rr, cc, n + 1)) return true;
        }
        board[r][c] = letter;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size(), c = board[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
