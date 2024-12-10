class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        vector<vector<int>> lengths(26);
        
        int start = 0;
        for (int i = 1; i <= n; i++) {
            if (i == n || s[i] != s[start]) {
                int len = i - start;
                lengths[s[start] - 'a'].push_back(len);
                start = i;
            }
        }
        
        int maxLen = -1;
        for (int c = 0; c < 26; c++) {
            if (lengths[c].empty()) continue;
            
            sort(lengths[c].rbegin(), lengths[c].rend());
            
            for (int len = 1; len <= lengths[c][0]; len++) {
                int count = 0;
                for (int l : lengths[c]) {
                    count += max(0, l - len + 1);
                    if (count >= 3) {
                        maxLen = max(maxLen, len);
                        break;
                    }
                }
            }
        }
        
        return maxLen;
    }
};