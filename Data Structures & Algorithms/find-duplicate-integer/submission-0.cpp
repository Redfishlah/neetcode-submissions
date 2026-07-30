class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto n: nums){
            int pos = abs(n) - 1;
            if(nums[pos] < 0) return abs(n);
            nums[pos] *= -1;
        }
        return -1;
    }
};
