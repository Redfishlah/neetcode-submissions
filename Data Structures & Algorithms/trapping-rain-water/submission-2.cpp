class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int res = 0, h = height.size();

        vector<int> lMax(h), rMax(h);
        lMax[0] = height[0];
        rMax[h - 1] = height[h - 1];
        for(int i = 1; i < h; i++){
            lMax[i] = max(height[i], lMax[i - 1]);
        }
        for(int i = h - 2; i >= 0; i--){
            rMax[i] = max(height[i], rMax[i + 1]);
        }
        for (int i = 0; i < h; i++) {
            res += min(lMax[i], rMax[i]) - height[i];
        }
        return res;
    }
};