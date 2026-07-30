class Solution {
public:
    string multiply(string num1, string num2) {
        string result = "";
        if(num1 == "0" || num2 == "0") return "0";
        int len1 = num1.size(), len2 = num2.size();
        vector<int> res(len1 + len2, 0);
        for(int i = len1 -1; i >= 0; i--){
            for(int j = len2 - 1; j >= 0; j--){
                int tmp = (num1[i] - '0') * (num2[j] - '0');
                int carry = i + j, cur = i + j + 1, sum = tmp + res[cur];
                res[cur] = sum % 10;
                res[carry] += sum / 10;
            }
        }
        for(int dig: res){
            if(!(result.empty() && dig == 0)) result.push_back(dig + '0');
        }
        return result;
    }
};
