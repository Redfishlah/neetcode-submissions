class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> order;
        int res = 0;
        for(int n: nums) order.insert(n);
        for(int o: order){
            // if existed o-1, it means it is not the beginning of the streak 
            if(!order.count(o - 1)){
                int cur = o;
                int curMax = 1;
                while(order.count(cur + 1)){
                    cur++;
                    curMax++;
                }
                res = max(res, curMax);
            }
        }
        return res;
    }
};
