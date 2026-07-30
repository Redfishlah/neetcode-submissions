class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, len = heights.size();
        stack<pair<int, int>> stack; // pair: (index, height)

        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            while (!stack.empty() && stack.top().second > heights[i]) {
                // met shorter one, calculate former ones
                pair<int, int> top = stack.top();
                int index = top.first, height = top.second;
                maxArea = max(maxArea, height * (i - index));
                start = index;
                stack.pop();
            }
            stack.push({start, heights[i]});
        }
        // all those can reach rightest
        while (!stack.empty()) {
            int index = stack.top().first;
            int height = stack.top().second;
            maxArea = max(maxArea, height * (len - index));
            stack.pop();
        }
        return maxArea;
    }
};