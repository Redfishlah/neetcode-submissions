class Solution {
private:
    vector<string> pad = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void backtrack(string& digits, int n, string& cur, vector<string>& res){
        if(n == digits.size()){
            res.push_back(cur);
            return;
        }
        int digit = digits[n] - '2';
        string& cands = pad[digit];
        for(char c: cands){
            cur.push_back(c);
            backtrack(digits, n + 1, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string cur;
        vector<string> res;
        backtrack(digits, 0, cur, res);
        return res;
    }
};