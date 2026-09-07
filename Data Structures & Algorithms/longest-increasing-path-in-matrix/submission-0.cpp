class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> indegree(row, vector<int>(col, 0));
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // count the number of smaller neighbors as its own degree
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                for(auto& d:dir){
                    int nr = r + d[0], nc = c + d[1];
                    if(nr >= 0 && nr < row && nc >= 0 && nc < col && matrix[r][c] > matrix[nr][nc]) indegree[r][c]++; 
                }
            }
        }
        // those whose indgree is 0, as a start node
        queue<pair<int, int>> q;
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(indegree[r][c] == 0) q.push({r, c});
            }
        }
        // to track nodes, put every indegree=0 into the queue to make it a new start node
        int LIS = 0; // longest increasing sequence
        while(!q.empty()){
            int qlen = q.size();
            for(int i = 0; i < qlen; i++){
                auto [r, c] = q.front();
                q.pop();
                for(auto& d:dir){
                    int nr = r + d[0], nc = c + d[1];
                    if(nr >= 0 && nr < row && nc >= 0 && nc < col && matrix[nr][nc] > matrix[r][c]){
                        if(--indegree[nr][nc] == 0) q.push({nr, nc});
                    }
                }
            }
            LIS++;
        }
        return LIS;
    }
};
