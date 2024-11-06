class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(128, -1);
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < s.length(); end++) {
            if (lastSeen[s[end]] >= start) {
                start = lastSeen[s[end]] + 1;
            }

            lastSeen[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};