class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> tmp;
        int l = 0, res = 0;
        for(int r = 0; r < s.size(); r++){
            while(tmp.find(s[r]) != tmp.end()){
                tmp.erase(s[l]);
                l++;
            }
            tmp.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
