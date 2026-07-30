class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> tmp;
        for(auto &s: strs){
            vector<int> acc(26, 0);
            for(char c: s){
                acc[c - 'a']++;
            }
            string key = to_string(acc[0]);
            for(int i = 1; i < 26; i++){
                key += ',' + to_string(acc[i]);
            }
            tmp[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto &pair: tmp){
            res.push_back(pair.second);
        }
        return res;
    }
};
