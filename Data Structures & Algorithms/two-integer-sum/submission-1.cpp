class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            auto j = find(nums.begin() + 1 + i, nums.end(), target - nums[i]);
            if( j != nums.end()) return {i, distance(nums.begin(), j)};
        }
    }
};
