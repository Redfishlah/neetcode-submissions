class Solution {
private:
    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    void backtrack(string& s, int l, vector<string>& cur, vector<vector<string>>& res){
        // means the whole checked substr is a palindrome, that would make l = size + 1
        if(l == s.length()){
            res.push_back(cur);
            return;
        }
        for(int r = l; r < s.length(); r++){
            if(isPalindrome(s, l, r)){ // if hit then see if there are more in the rest of the s
                cur.push_back(s.substr(l, r - l + 1));
                backtrack(s, r + 1, cur, res);// test th erest of the s
                cur.pop_back();// finish searching the cut
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