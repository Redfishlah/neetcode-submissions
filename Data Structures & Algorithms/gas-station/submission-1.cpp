class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = gas.size() - 1, end = 0, cap = gas[start] - cost[start];
        while(start > end){
            if(cap < 0){
                start--;
                cap += gas[start] - cost[start];
            } 
            else{
                cap += gas[end] - cost[end];
                end++;
            }
        }
        return cap >= 0? start: -1;
    }
};
