class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;            
            if(nums[i] > 0) break;
            int target = 0 - nums[i], l = i + 1, r = nums.size() - 1;
            while(l < r){
                if(nums[l] + nums[r] == target){
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1]) l++;
                } 
                else if(nums[l] + nums[r] > target) r--;
                else l++;
            }
        }
        return res;
    }
};