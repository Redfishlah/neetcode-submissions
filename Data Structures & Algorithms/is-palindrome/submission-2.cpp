class Solution {
private:
    bool check(char c){
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r){
            if(!check(s[l])) l++;
            else if(!check(s[r])) r--;
            else if(tolower(s[l]) != tolower(s[r])) return false;
            else{
                l++;
                r--;                
            }
        }
        return true;
    }
};
