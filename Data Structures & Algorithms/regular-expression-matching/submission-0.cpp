class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size(), plen = p.size();
        vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
        dp[0][0] = true;
        // to handle 'x*' matches an empty string
        for(int j = 1; j <= plen; j++){
            if(p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
        }
        // normal cases
        for(int i = 1; i <= slen; i++){
            for(int j = 1; j <= plen; j++){
                // if same or as a '.', comtinue the streak
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.') dp[i][j] = dp[i - 1][j - 1];
                // if met '*', see if erase the preceding element or consume an dkeep the star
                else if(p[j - 1] == '*'){
                    // erase the preceding element
                    dp[i][j] = dp[i][j - 2];
                    // if the letter before the '*' matches current string letter or is '.', consume the string letter and keep the '*' active to maybe use again
                    if(p[j - 2] == s[i - 1] || p[j - 2] == '.') dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        } 
        return dp[slen][plen];
    }
};
