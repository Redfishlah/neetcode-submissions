class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> res(queries.size(), -1);
        int i = 0;
        for (auto& [q, originalIndex] : sortedQueries) {
            while (i < intervals.size() && intervals[i][0] <= q) {
                int start = intervals[i][0];
                int end = intervals[i][1];
                minHeap.push({end - start + 1, end});
                i++;
            }
            while (!minHeap.empty() && minHeap.top().second < q) {
                minHeap.pop();
            }
            if (!minHeap.empty()) res[originalIndex] = minHeap.top().first;
        }
        return res;
    }
};