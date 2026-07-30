class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n: nums) sum += n;
        if(sum % 2 == 1) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(int i = 0; i < nums.size(); i++){
            for(int j = target; j >= nums[i]; j--){
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};