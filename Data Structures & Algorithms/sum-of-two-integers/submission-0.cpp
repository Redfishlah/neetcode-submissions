class Solution {
public:
    int getSum(int a, int b) {
        while(a != 0){
            int carry = (b & a) << 1;
            b ^= a;
            a = carry;
        }
        return b;
    }
};
