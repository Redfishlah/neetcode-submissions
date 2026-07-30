class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); i++){
            res += to_string(strs[i].size()) + '#' + strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res = {};
        int l = 0;
        while(l < s.size()){
            int r = l;
            while(s[r] != '#') r++;
            int len = stoi(s.substr(l, r - l));
            res.push_back(s.substr(r + 1, len));
            l = r + 1 + len; 
        }
        return res;
    }
};
