class Solution {
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& tmp, int r, int c){
        tmp[r][c] = true;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0; i < 4; i++) {
            int nr = r + dirs[i][0], nc = c + dirs[i][1];
            if(nr < 0 || nr >= heights.size() || nc < 0 || nc >= heights[0].size()) continue;
            if(tmp[nr][nc]) continue;
            if(heights[nr][nc] >= heights[r][c]) dfs(heights, tmp, nr, nc);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        if(m == 0 || n == 0) return {};
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        for(int tb = 0; tb < n; tb++){ // from top and bottom
            dfs(heights, pac, 0, tb);
            dfs(heights, atl, m - 1, tb);
        }
        for(int lr = 0; lr < m; lr++){ // from left and right
            dfs(heights, pac, lr, 0);
            dfs(heights, atl, lr, n - 1);
        }
        vector<vector<int>> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pac[i][j] && atl[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};
