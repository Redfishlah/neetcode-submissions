class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(numCourses); // Adjacency List
        vector<int> inDeg(numCourses, 0);
        for(auto& p: prereq){
            int course = p[0], pre = p[1];
            adj[pre].push_back(course);
            inDeg[course]++; // how many courses taken before taking this 
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDeg[i] == 0) q.push(i); // those w/o prereq
        }
        int taken = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop(); // make the clasee be taken
            taken++;
            for(int next: adj[cur]){
                inDeg[next]--; // minus one prereq due to taken one
                if(inDeg[next] == 0) q.push(next);
            }
        }
        return taken == numCourses;
    }
};