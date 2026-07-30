class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int acc = 0;
        for(int n: nums) acc += n;
        int exp = nums.size() * (nums.size() + 1) /2;
        return exp - acc;
    }
};
