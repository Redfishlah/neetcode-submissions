class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        for(int i = 0; i < s.size(); i++) last[s[i]] = i;
        vector<int> res;
        int l = 0, r = 0;
        for(int i = 0; i < s.size(); i++){
            r = max(r, last[s[i]]);
            if(i == r){
                res.push_back(r - l + 1);
                i = r;
                l = r + 1;
            } 
        }
        return res;
    }
};
