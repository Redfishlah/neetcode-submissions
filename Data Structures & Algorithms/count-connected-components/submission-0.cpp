class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        int res = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                res++;
                vis[i] = true;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    for(auto n: adj[cur]){
                        if(!vis[n]){
                            vis[n] = true;
                            q.push(n);
                        }
                    }
                }
            }
        }
        return res;
    }
};
