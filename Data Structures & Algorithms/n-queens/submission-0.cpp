class Solution {
private:
    void backtrack(int row, int n, vector<string>& board, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, vector<vector<string>>& res) {
        // Base case: We successfully placed a queen in the final row. 
        // We survived the whole board!
        if (row == n) {
            res.push_back(board);
            return;
        }
        // Try placing a queen in every column of the current row
        for (int col = 0; col < n; col++) {
            // Calculate the unique IDs for the two diagonals crossing this cell
            int d1 = row - col + n - 1; // Negative diagonal (top-left to bottom-right)
            int d2 = row + col;         // Positive diagonal (bottom-left to top-right)
            // Pruning check: Is this cell under attack?
            if (cols[col] || diag1[d1] || diag2[d2]) continue; // Unsafe, skip to the next column
            // 1. Choose: Place the queen and trigger the attack tripwires
            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = true;
            // 2. Explore: Move down to the next row
            backtrack(row + 1, n, board, cols, diag1, diag2, res);
            // 3. Un-choose (Backtrack): Remove the queen and disable the tripwires
            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        // Initialize an empty N x N board filled with '.'
        vector<string> board(n, string(n, '.'));
        // Fast O(1) lookup arrays for attack zones
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false); // row - col + (n - 1)
        vector<bool> diag2(2 * n - 1, false); // row + col
        // Start placing queens at row 0
        backtrack(0, n, board, cols, diag1, diag2, res);
        return res;
    }
};