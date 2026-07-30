class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, res = nums[0];
        while(l <= r){
            if(nums[l] < nums[r]) return res < nums[l]? res: nums[l];
            int mid = (l + r) / 2;
            res = min(res, nums[mid]);
            if(nums[mid] >= nums[l]) l = mid + 1;
            else r = mid - 1;
        }
        return res;
    }
};
