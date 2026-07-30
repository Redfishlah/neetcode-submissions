class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<pair<int, int>> freq; // Stores {number, count}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> count;
        for(auto c: candidates) count[c]++;
        for(auto& [number, count]: count) freq.push_back({number, count});
        dfs(0, target);
        return res;
    }
    void dfs(int i, int curT){
        if(curT == 0){
            res.push_back(cur);
            return;
        }
        if(curT < 0 || i >= freq.size()) return; // out of bound

        int num = freq[i].first;
        int countMax = freq[i].second;

        for(int count = 0; count <= countMax; count++){
            int numAddUp = num * count;
            if(curT - numAddUp < 0) break; // out of bound

            for(int j = 0; j < count; j++){
                cur.push_back(num);
            }
            dfs(i + 1, curT - numAddUp);
            
            for(int k = 0; k < count; k++){
                cur.pop_back();
            }
        }
    }
};
