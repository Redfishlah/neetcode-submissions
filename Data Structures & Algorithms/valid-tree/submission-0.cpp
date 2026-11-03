class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(0);
        vis[0] = true;
        int reached = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            reached++;
            for(int n: adj[cur]){
                if(!vis[n]){
                    vis[n] = true;
                    q.push(n);
                }
            }
        }
        return reached == n;
    }
};