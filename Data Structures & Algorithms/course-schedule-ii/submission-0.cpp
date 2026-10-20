class Solution {
public:
    vector<int> findOrder(int nums, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(nums);
        vector<int> inDeg(nums, 0);
        vector<int> res;
        for(auto p: prereq){
            int course = p[0], pre = p[1];
            adj[pre].push_back(course);
            inDeg[course]++;
        }
        queue<int> q;
        for(int i = 0; i < nums; i++){
            if(inDeg[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int cur = q.front();
            res.push_back(cur);
            q.pop();
            for(auto next: adj[cur]){
                inDeg[next]--;
                if(inDeg[next] == 0) q.push(next);
            }
        }
        return res.size() == nums ? res : vector<int>{};
    }
};

