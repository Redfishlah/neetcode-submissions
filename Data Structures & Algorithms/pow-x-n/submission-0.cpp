class Solution {
public:
    double myPow(double x, int n) {
        double res = x;
        if(x == 0) return 0;
        else if(n == 1) return x;
        else if(x == 1 || n == 0) return 1;
        else if(n > 0){
            while(n > 1){
                res *= x;
                n--;
            }
        }
        else{
            while(n < 1){
                res /= x;
                n++;
            }
        }
        return res;
    }
};
