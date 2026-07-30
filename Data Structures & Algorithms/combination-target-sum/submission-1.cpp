class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(0, {}, 0, nums, target);
        return res;
    }
    void dfs(int i, vector<int> cur, int sum, vector<int>& nums, int target){
        if(sum == target){
            res.push_back(cur);
            return;
        } 
        for(int j = i; j < nums.size(); j++){
            if(sum + nums[j] > target) return;
            cur.push_back(nums[j]);
            dfs(j, cur, sum + nums[j], nums, target);
            // pop back the new elements(bigger than others) to see 
            // if small repeated number would work
            cur.pop_back();
        }

    }
};
