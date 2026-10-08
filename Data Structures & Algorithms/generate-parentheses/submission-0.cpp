class Solution {
private:
    void backtrack(string& curr, int open, int close, int n, vector<string>& res) {
        // Base case: If the string length reaches 2 * n, we have a complete valid combination
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }
        // Choice 1: Add an opening bracket if we still have some left
        if (open < n) {
            curr.push_back('(');
            backtrack(curr, open + 1, close, n, res);
            curr.pop_back(); // Backtrack: undo the choice
        }

        // Choice 2: Add a closing bracket if it won't exceed the opening count
        if (close < open) {
            curr.push_back(')');
            backtrack(curr, open, close + 1, n, res);
            curr.pop_back(); // Backtrack: undo the choice
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        backtrack(curr, 0, 0, n, res);
        return res;
    }
};