class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            helper(s, i, i, count);
            helper(s, i, i + 1, count);
        }
        return count;
    }
    
    void helper(string& s, int left, int right, int& count) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }
};