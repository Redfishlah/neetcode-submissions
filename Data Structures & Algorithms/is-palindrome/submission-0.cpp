class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        for(char c:s){
            if(isalnum(c)) ss += tolower(c);
        }
        return ss == string(ss.rbegin(), ss.rend());
    }
};
