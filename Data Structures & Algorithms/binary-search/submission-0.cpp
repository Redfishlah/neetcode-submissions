class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            if(nums[(r + l) / 2] == target) return (r + l) / 2;
            else if(nums[(r + l) / 2] > target) r = (r + l) / 2 - 1;
            else l = (r + l) / 2 + 1;
        }
        return -1;
    }
};
