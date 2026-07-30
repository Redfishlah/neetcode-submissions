class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> tmp;
        for(int n: nums) tmp[n]++;
        for(auto& [n, count]: tmp){
            if(count != 2) return n;
        }
        return -1;
    }
};
