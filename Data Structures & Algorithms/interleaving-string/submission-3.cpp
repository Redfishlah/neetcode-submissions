class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        stack<pair<int, int>> stk;
        vector<vector<bool>> visited(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        stk.push({0, 0});
        visited[0][0] = true;
        while (!stk.empty()) {
            auto [i, j] = stk.top();
            stk.pop();
            if (i == s1.size() && j == s2.size()) return true;
            int k = i + j;
            // Path 1: Can we pull the next character from s1?
            if (i < s1.size() && s1[i] == s3[k] && !visited[i + 1][j]) {
                stk.push({i + 1, j});
                visited[i + 1][j] = true;
            }
            // Path 2: Can we pull the next character from s2?
            if (j < s2.size() && s2[j] == s3[k] && !visited[i][j + 1]) {
                stk.push({i, j + 1});
                visited[i][j + 1] = true;
            }
        }
        return false;
    }
};