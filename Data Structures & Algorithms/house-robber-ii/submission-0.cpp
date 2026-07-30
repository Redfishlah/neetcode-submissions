class Solution {
public:
    int rob(vector<int>& n) {
        if(n.empty()) return 0;
        int len = n.size();
        if(len == 1) return n[0];
        if(len == 2) return max(n[0], n[1]);
        vector<int> dp1(len - 1), dp2(len);
        dp1[0] = n[0];
        dp1[1] = max(n[0], n[1]);
        for(int i = 2; i < len - 1; i++){
            dp1[i] = max(dp1[i - 1], n[i] + dp1[i - 2]);
        }
        dp2[0] = 0;
        dp2[1] = n[1];
        dp2[2] = max(n[1], n[2]);
        for(int i = 3; i < len; i++){
            dp2[i] = max(dp2[i - 1], n[i] + dp2[i - 2]);
        }
        return max(dp1.back(), dp2.back());
    }
};
