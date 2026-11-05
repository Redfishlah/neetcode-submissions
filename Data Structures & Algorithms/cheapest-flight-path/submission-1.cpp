class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& f: flights){
            adj[f[0]].push_back({f[1], f[2]}); // {neighborAirport, cost to there}
        }
        vector<int> cost(n, INT_MAX);// cost to each airport
        cost[src] = 0; // cost of src -> src
        queue<pair<int, int>> q; // queue for {airport, cost so far}
        q.push({src, 0});
        int stop = 0;
        while(!q.empty() && stop <= k){
            int choice = q.size(); // could take different routes
            for(int i = 0; i < choice; i++){
                auto [curAP, curCost] = q.front(); // the path taken
                q.pop();
                for(const auto& edge: adj[curAP]){ // all neighbors if not dupicate
                    int nextAP = edge.first, nextCost = edge.second;
                    if(curCost + nextCost < cost[nextAP]){
                        cost[nextAP] = curCost + nextCost;
                        q.push({nextAP, cost[nextAP]});
                    }
                }
            }
            stop++;
        }
        return cost[dst] != INT_MAX? cost[dst]: -1; // use finite steps to see if dst is reachable
    }
};