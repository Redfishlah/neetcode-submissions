class Solution {
private:
    vector<int> parent, rank;
    int find(int x){
        return parent[x] == x? x: parent[x] = find(parent[x]);
    }
    bool unionNodes(int x, int y){
        int rootX = find(x), rootY = find(y);
        if(rootX == rootY) return false;
        if(rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else if(rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else{
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        for(auto& e: edges){
            if(!unionNodes(e[0], e[1])) return e;
        }
        return {};
    }
};