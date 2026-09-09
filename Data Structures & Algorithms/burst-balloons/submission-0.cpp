class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> pad(n + 2, 1);
        for(int i = 1; i <= n; i++){
            pad[i] = nums[i - 1];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int l = n; l >= 1; l--){
            for(int r = l; r <= n; r++){
                for(int i = l; i <= r; i++){
                    dp[l][r] = max(dp[l][r], pad[l - 1] * pad[i] * pad[r + 1] + dp[l][i - 1] + dp[i + 1][r]);
                }
            }
        }
        return dp[1][n];
    }
};
