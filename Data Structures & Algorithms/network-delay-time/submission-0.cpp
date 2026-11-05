class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1); // neighbor and time to it
        for(auto& t: times){
            adj[t[0]].push_back({t[1], t[2]}); // {neighbor, time}
        }
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;// the starting node
        // to store {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        while(!q.empty()){ // Dijkstra's Algorithm
            auto [curDis, node] = q.top();
            q.pop();
            if(curDis > dis[node]) continue;
            for(auto& edge: adj[node]){
                int v = edge.first;
                int w = edge.second;
                if(dis[node] + w < dis[v]){
                    dis[v] = dis[node] + w;
                    q.push({dis[v], v});
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
            if(dis[i] == INT_MAX) return -1;
            res = max(res, dis[i]);
        }
        return res;
    }
};
