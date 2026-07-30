class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for(auto i: intervals){
            int l = i[0], r = i[1], lastR = res.back()[1];
            if(l <= lastR) res.back()[1] = max(lastR, r);
            else res.push_back({l, r});
        }
        return res;
    }
};
