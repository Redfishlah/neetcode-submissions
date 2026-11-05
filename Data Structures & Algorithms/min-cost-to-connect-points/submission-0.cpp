class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);
        int cost = 0, nodes = 0;
        pq.push({0, 0}); // start from node 0 with weight 0(node 0 -> node 0)
        while(!pq.empty() && nodes < n){
            auto[w, curNode] = pq.top();
            pq.pop();
            if(visited[curNode]) continue; // already connected
            visited[curNode] = true;
            cost += w;
            nodes++;
            for(int next = 0; next < n; next++){
                if(!visited[next]){
                    int d = abs(points[curNode][0] - points[next][0]) + abs(points[curNode][1] - points[next][1]);
                    pq.push({d, next});
                }
            }
        }
        return cost;
    }
};
