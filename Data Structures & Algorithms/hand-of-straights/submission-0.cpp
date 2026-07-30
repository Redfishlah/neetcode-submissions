class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        unordered_map<int, int> count;
        for(auto h: hand) count[h]++;
        for(int h: hand){
            if(count[h]){
                for(int i = h; i < h + groupSize; i++){
                    if(!count[i]) return false;
                    else count[i]--;
                }
            }
        }
        return true;
    }
};
