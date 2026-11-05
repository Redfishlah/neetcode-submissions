class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> targets;
    vector<string> route;
    void dfs(const string& ap){
        while(targets.count(ap) && !targets[ap].empty()){ // the airport is found and there not the final
            string next = targets[ap].top(); // use top instead of front cuz priority_queue 
            targets[ap].pop();
            dfs(next);
        }
        route.push_back(ap); // when getting out of the loop, means no tickets to get out
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& t: tickets){
            targets[t[0]].push(t[1]);
        }
        dfs("JFK");
        reverse(route.begin(), route.end()); // cuz the final destination lines first
        return route;
    }
};
