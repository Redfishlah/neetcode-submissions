class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        
        // s1 cannot be a substring if it is longer than s2
        if (n > m) return false;

        // Use arrays of size 26 instead of unordered_map for speed
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        // 1. Initialize the frequency maps for the first window
        for (int i = 0; i < n; ++i) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        // 2. Check if the very first window is a match
        if (count1 == count2) return true;

        // 3. Slide the window across the rest of s2
        for (int i = n; i < m; ++i) {
            // Add the new character entering the window (right side)
            count2[s2[i] - 'a']++;
            
            // Remove the old character leaving the window (left side)
            count2[s2[i - n] - 'a']--;

            // Compare the maps. In C++, comparing two fixed-size vectors is fast.
            if (count1 == count2) return true;
        }

        return false;
    }
};