class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int res = 0, l = 0, fMax = 0;
        for(int r = 0; r < s.size(); r++){
            count[s[r]]++;
            fMax = max(fMax, count[s[r]]);
            while((r - l + 1) - fMax > k){
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
