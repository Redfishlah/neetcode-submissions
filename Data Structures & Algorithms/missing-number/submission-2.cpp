class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l+r) /2;
            if(mid == nums[mid]) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};
