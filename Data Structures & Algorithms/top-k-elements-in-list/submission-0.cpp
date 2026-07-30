class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> acc;
        for(int n:nums) acc[n]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto [a,b]: acc) bucket[b].push_back(a);
        vector<int> res;
        for(int i = nums.size(); i >= 0; i--){
            for(int n: bucket[i]){
                res.push_back(n);
                if(res.size() == k) return res;
            }
        }
        return {};
    }
};
