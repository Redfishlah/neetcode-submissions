class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        for(int i = 0; i < nums.size(); i++){
            res = max(res, nums[i]);
            int tmp = nums[i];
            for(int j = i + 1; j < nums.size(); j++){
                tmp *= nums[j];
                res = max(res, tmp);
            }
        }
        return res;
    }
};
