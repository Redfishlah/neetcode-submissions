class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, len = intervals.size();
        // for those intervals[i].fin < newIntervals.start
        while(i < len && newInterval[0] > intervals[i][1]){
            res.push_back(intervals[i]);
            i++;
        }
        // for the overlapping one(could overlap more than one)
        while(i < len && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        // rest of all
        while(i < len){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
