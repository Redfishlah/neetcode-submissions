class Solution {
public:
    int numDistinct(string s, string t) {
        int r = s.length(), col = t.length();
        vector<vector<long long>> dp(r + 1, vector<long long>(col + 1, 0));
        for(int i = 0; i <= r; i++){
            dp[i][col]++;
        } 
        for(int i = r -1; i >= 0; i--){
            for(int j = col - 1; j >= 0; j--){
                dp[i][j] = dp[i + 1][j];
                if(s[i] == t[j]) dp[i][j] += dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};
