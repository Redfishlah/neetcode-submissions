class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> tmp;
        for(int n: nums){
            if(tmp.count(n)) tmp.erase(n);
            else tmp.insert(n);
        }
        return *tmp.begin();
    }
};
