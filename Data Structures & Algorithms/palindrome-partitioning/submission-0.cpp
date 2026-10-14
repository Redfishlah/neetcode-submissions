class Solution {
private:
    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    void backtrack(string& s, int l, vector<string>& cur, vector<vector<string>>& res){
        if(l == s.length()){
            res.push_back(cur);
            return;
        }
        for(int r = l; r < s.length(); r++){
            if(isPalindrome(s, l, r)){
                cur.push_back(s.substr(l, r - l + 1));
                backtrack(s, r + 1, cur, res);
                cur.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        backtrack(s, 0, cur, res);
        return res;
    }
};