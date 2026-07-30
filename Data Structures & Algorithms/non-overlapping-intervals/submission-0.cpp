class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){return a[1] < b[1];});
        int len = intervals.size();
        vector<int> dp(len, 0);
        for(int i = 0; i < len; i++){
            dp[i] = 1;
            for(int j = 0; j < len; j++){
                if(intervals[j][1] <= intervals[i][0]) dp[i] = max(dp[i], 1 + dp[j]); // no overlap
            }
        }
        sort(dp.begin(), dp.end());
        return len - dp[len - 1];
    }
};
