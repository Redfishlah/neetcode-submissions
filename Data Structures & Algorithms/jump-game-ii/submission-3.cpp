class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, l = 0, r = 0;
        while(r < nums.size() - 1){
            int rr = 0;
            for(int i = l; i <= r; i++){
                rr = max(rr, i + nums[i]);
            }
            l = r + 1;
            r = rr;
            res++;
        }
        return res;
    }
};
