class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > totalSum || (target + totalSum) % 2 != 0) return 0; 
        int subsetSum = (target + totalSum) / 2;
        // dp[j] stores the number of ways to reach sum 'j'
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1; // 1 way to make sum 0 (pick no elements)
        // Standard 1D 0/1 Knapsack loop
        for (int num : nums) {
            for (int j = subsetSum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        return dp[subsetSum];
    }
};