class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            // "Hamming weight" and "population count" (or "popcount") 
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};