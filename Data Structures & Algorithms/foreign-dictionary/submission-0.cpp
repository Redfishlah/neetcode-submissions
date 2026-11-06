class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj; // adjacency
        unordered_map<char, int> inDegree; // how many letters should come before it
        // initialize all letters appeared
        for(const string w: words){
            for(char c: w){
                inDegree[c] = 0;
            }
        }
        // to check what rules can be discovered
        for(int i = 0; i < words.size() - 1; i++){ 
            string w1 = words[i], w2 = words[i + 1];
            if(w1.length() > w2.length() && w1.substr(0, w2.length()) == w2) return ""; // shorter prefix should comes first
            for(int j = 0; j < min(w1.length(), w2.length()); j++){
                if(w1[j] != w2[j]){ // if the first letter the same, check the second letter
                    char a = w1[j], b = w2[j];
                    if(adj[a].find(b) == adj[a].end()){ // new a comes before b rule detected
                        adj[a].insert(b);
                        inDegree[b]++; 
                    }
                    break;
                }
            }
        }
        queue<char> q;
        for(const auto& [c, deg]: inDegree){
            if(deg == 0) q.push(c);
        }
        string res = "";
        // check the order
        while(!q.empty()){
            char cur = q.front();
            q.pop();
            res += cur;
            for(char n: adj[cur]){
                inDegree[n]--;
                if(inDegree[n] == 0) q.push(n);
            }
        }
        return res.length() == inDegree.size()? res: "";
    }
};