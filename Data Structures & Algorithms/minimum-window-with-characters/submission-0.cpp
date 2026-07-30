class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty() || s.size() < t.size()) return "";
        unordered_map<char, int> countT, wd;

        for(auto c: t) countT[c]++;

        int sup = 0, d = countT.size(); // to match demand and supply
        pair<int, int> sub = {-1, -1};
        int rlen = s.size() + 1, l = 0;
        
        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            wd[c]++;
            if(countT.count(c) && wd[c] == countT[c]) sup++;
            while(sup == d){
                if((r - l + 1) < rlen){
                    rlen = r - l + 1;
                    sub = {l, r};
                }
                int left = s[l];
                wd[left]--;
                if(countT.count(left) && wd[left] < countT[left]) sup--;
                l++;
            }
        }
        return rlen == s.size() + 1? "" : s.substr(sub.first, rlen);
    }
};
