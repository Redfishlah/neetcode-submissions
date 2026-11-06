class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // Min Heap of {time, {row, column}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            auto [t, address] = pq.top(); // [time, {row, column}]
            auto [r, c] = address; // [row, column]
            pq.pop();
            if(r == n - 1 && c == n - 1) return t; // the bottom right
            for(auto& d: dir){
                int nr = r + d[0], nc = c + d[1];
                if(nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    int nextTime =  max(t, grid[nr][nc]); // the time would be thrown into pq, no impact on the result
                    pq.push({nextTime, {nr, nc}}); // push them all into pq, the smaller grid always processes first 
                }
            }
        }
        return -1;
    }
};