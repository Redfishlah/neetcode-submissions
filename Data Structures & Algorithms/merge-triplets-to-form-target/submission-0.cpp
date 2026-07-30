class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool first = false, second = false, third = false;
        for(const auto& t: triplets){
            first |= (t[0] == target[0] && t[1] <= target[1] && t[2] <= target[2]);
            second |= (t[1] == target[1] && t[0] <= target[0] && t[2] <= target[2]);
            third |= (t[2] == target[2] && t[1] <= target[1] && t[0] <= target[0]);
            if(first && second && third) return true;
        }
        return false;
    }
};
