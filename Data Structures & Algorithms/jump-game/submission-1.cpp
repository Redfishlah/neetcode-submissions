class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<bool> dp(len, false);
        dp[len - 1] = true;
        for(int i = len - 2; i >= 0; i--){
            int reachable = min(len - 1, i + nums[i]);
            for(int j = i; j <= reachable; j++){
                if(dp[j] == true){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
