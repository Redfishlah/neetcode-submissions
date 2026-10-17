class Solution {
private:
    void dfs(vector<vector<char>>& board, int r, int c){
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != 'O') return;
        board[r][c] = 'A';
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i < 4; i++){
            int nr = r + dir[i][0], nc = c + dir[i][1];
            dfs(board, nr, nc);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        if(m == 0 || n == 0) return;
        for(int tb = 0; tb < n; tb++){// start from top and bottom
            if(board[0][tb] == 'O') dfs(board, 0, tb);
            if(board[m - 1][tb] == 'O') dfs(board, m - 1, tb);
        }
        for(int lr = 0; lr < m; lr++){// start from left and right
            if(board[lr][0] == 'O') dfs(board, lr, 0);
            if(board[lr][n -1] == 'O') dfs(board, lr, n - 1);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'A') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};