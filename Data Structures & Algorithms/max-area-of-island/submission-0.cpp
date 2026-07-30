class Solution {
public:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int r = grid.size(), c = grid[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1){
                    res = max(res, dfs(grid, i, j));
                } 
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& grid, int i, int j){
        int r = grid.size(), c = grid[0].size();
        if(i < 0 || j < 0 || i >= r || j >= c || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        int res = 1;
        for(int k = 0; k < 4; k++) res += dfs(grid, i + dir[k][0], j + dir[k][1]);
        return res;
    }
};