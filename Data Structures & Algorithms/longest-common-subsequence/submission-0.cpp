class Solution {
public:
    vector<vector<int>> memo;
    int longestCommonSubsequence(string text1, string text2) {
        memo.resize(text1.size(), vector<int>(text2.size(), -1));
        return dfs(text1, text2, 0, 0);
    }
    int dfs(string& x, string& y, int a, int b){
        // out of bound
        if(a == x.size() || b == y.size()) return 0;
        // if checked
        if(memo[a][b] != -1) return memo[a][b];
        // if the same
        if(x[a] == y[b]) memo[a][b] = 1 + dfs(x, y, a + 1, b + 1);
        // not the same
        else memo[a][b] = max(dfs(x, y, a + 1, b), dfs(x, y, a, b + 1));
        return memo[a][b];
    }
};
