class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int res = 0, l = 0, r = 1;
        while(r < prices.size()){
            if(prices[r] > prices[l]){
                res = max(res, prices[r] - prices[l]);
                r++;
            } 
            else if(prices[r] <= prices[l]){
                l = r;
                r += 1;
            }
        }
        return res;
    }
};
