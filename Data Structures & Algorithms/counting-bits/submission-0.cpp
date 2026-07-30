class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for(int i = 0; i <= n; i++){
            res[i] = count(i);
        }
        return res;
    }
    int count(int x){
        int res = 0;
        while(x > 0){
            if(x % 2 != 0) res++;
            x /= 2;
        }
        return res;
    }
};
