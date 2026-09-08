class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
        int r = word1.size(), col = word2.size();
        vector<vector<int>> dp(r + 1, vector<int>(col + 1, 0));
        // what if word1 too short
        for(int i = 0; i <= r; i++){
            dp[i][col] = r - i;
        }
        // what if word2 too short
        for(int i = 0; i <= col; i++){
            dp[r][i] = col - i;
        }
        for(int i = r - 1; i >= 0; i--){
            for(int j = col - 1; j >= 0; j--){
                if(word1[i] == word2[j]) dp[i][j] = dp[i + 1][j + 1];
                else dp[i][j] = 1 + min(dp[i + 1][j + 1], min(dp[i][j + 1], dp[i + 1][j]));
            }
        }
        return dp[0][0];
    }
};
