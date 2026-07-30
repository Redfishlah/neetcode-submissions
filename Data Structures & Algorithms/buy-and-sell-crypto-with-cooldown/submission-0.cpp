class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            // State 1: We are looking to BUY
            int buy = dp[i + 1][0] - prices[i];      // Buy now, look to sell tomorrow
            int cooldownBuy = dp[i + 1][1];          // Do nothing, still look to buy tomorrow
            dp[i][1] = max(buy, cooldownBuy);

            // State 0: We are looking to SELL
            int sell = dp[i + 2][1] + prices[i];     // Sell now! Forced cooldown means jump to i + 2
            int cooldownSell = dp[i + 1][0];         // Do nothing, still look to sell tomorrow
            dp[i][0] = max(sell, cooldownSell);
        }
        return dp[0][1];
    }
};