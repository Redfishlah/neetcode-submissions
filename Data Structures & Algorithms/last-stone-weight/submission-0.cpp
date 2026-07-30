class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1){
            int len = stones.size();
            sort(stones.begin(), stones.end());
            int a = stones[len - 1], b = stones[len - 2];
            stones.pop_back();
            stones.pop_back();
            stones.push_back(a - b);
        }
        return stones[0];
        
    }
};
