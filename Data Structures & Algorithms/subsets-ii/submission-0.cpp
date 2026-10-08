class Solution {
private:
    void backtrack(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& res) {
        res.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;// Skip duplicates at same level of recursion
            curr.push_back(nums[i]);// 1. Choose
            backtrack(nums, i + 1, curr, res);// 2. Explore (move to i + 1, not start + 1)
            curr.pop_back();// 3. Un-choose (Backtrack)
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());// Step 1: Sort the array to group duplicates together
        backtrack(nums, 0, curr, res);// Step 2: Start backtracking
        return res;
    }
};