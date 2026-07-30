class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        long total = 1;
        int zero = 0;
        for(int n : nums){
            if(n == 0) zero++;
            else total *= n;
        } 
        if(zero > 1) return res;
        if(zero == 1){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0) res[i] = total;
            }
        }
        else{
            for(int i = 0; i < nums.size(); i++){
                res[i] = total / nums[i];
            }
        }
        return res;
    }
};
