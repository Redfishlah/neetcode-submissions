class Solution {
public:
    int numDecodings(string s) {
        int dp0 = 0, dp1 = 1, dp2 = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '0') dp0 = 0;
            else{
                dp0 = dp1;
                if(i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) dp0 += dp2;
            }
            dp2 = dp1;
            dp1 = dp0;
            dp0 = 0;
        }
        return dp1;

    }
};
