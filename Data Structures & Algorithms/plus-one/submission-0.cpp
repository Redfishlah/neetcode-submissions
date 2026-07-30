class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int tail = d.size() - 1;
        while (tail >= 0 && d[tail] == 9) {
            d[tail] = 0;
            tail--;
        }
        if (tail >= 0) d[tail] += 1;
        else d.insert(d.begin(), 1);
        return d;
    }
};
