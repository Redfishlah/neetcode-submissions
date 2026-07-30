class Solution {
public:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int r = grid.size(), c = grid[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    res++;
                } 
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        int r = grid.size(), c = grid[0].size();
        if(i < 0 || j < 0 || i >= r || j >= c || grid[i][j] == '0') return;
        grid[i][j] = '0';
        for(int k = 0; k < 4; k++) dfs(grid, i + dir[k][0], j + dir[k][1]);
    }

};
