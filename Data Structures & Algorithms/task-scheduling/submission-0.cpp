class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char t: tasks){
            freq[t - 'A']++;
        }
        int maxf = *max_element(freq.begin(), freq.end()), most = 0;
        for(int f: freq){
            if(f == maxf) most++;
        }
        return max((int)tasks.size(), ((maxf - 1) * (n + 1) + most));
    }
};
