class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            // 1. Choose: Swap the current element to the 'start' position
            swap(nums[start], nums[i]);
            // 2. Explore: Lock in the 'start' element, and permute the rest
            backtrack(nums, start + 1, res);
            // 3. Un-choose (Backtrack): Swap them back to restore the original array
            swap(nums[start], nums[i]);
        }
    }
};