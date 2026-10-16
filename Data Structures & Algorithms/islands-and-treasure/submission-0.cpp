class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 0 || n == 0) return;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) q.push({i, j});
            }
        }
        int dir[4][2] = {{-1, 0}, {1, 0}, {0 ,1}, {0, -1}};
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(int d = 0; d < 4; d++){
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];
                if(nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] != 2147483647) continue;
                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};
