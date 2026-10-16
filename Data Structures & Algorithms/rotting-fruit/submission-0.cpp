class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        if(fresh == 0) return 0;
        int res = 0, dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            int levelSize = q.size();
            bool rottenSpread = false;
            for(int i = 0; i < levelSize; i++){
                auto [r, c] = q.front();
                q.pop();
                for(int d = 0; d < 4; d++){
                    int nr = r + dir[d][0], nc = c + dir[d][1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != 1) continue;
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                    rottenSpread = true;
                }
            }
            if(rottenSpread) res++;
        }
        return fresh > 0? -1: res;
    }
};
