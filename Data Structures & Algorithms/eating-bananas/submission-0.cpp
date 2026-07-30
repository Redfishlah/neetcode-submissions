class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 0;
        for(int p: piles) r = max(r, p);
        cout<< r;
        int res = r;
        while(l <= r){
            int mid = (l + r)/ 2;
            int t = 0;
            for(int pil: piles){
                double p = pil;
                t += ceil(p / mid);
            } 
            if(t <= h){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }
};
