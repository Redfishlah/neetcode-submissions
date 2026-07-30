class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int len = temp.size();
        vector<int> res(len, 0);
        for(int i =  len - 2; i >= 0; i--){
            int j = i + 1;
            while(j < len && temp[j] <= temp[i]){
                if(res[j] == 0) break;
                j += res[j];
            }
            if(j < len && temp[j] > temp[i]) res[i] = j - i;
        }
        return res;
    }
};