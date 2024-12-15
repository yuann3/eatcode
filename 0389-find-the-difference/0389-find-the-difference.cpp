class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<char> ss(s.begin(), s.end());
        vector<char> ts(t.begin(), t.end());

        sort(ss.begin(), ss.end());
        sort(ts.begin(), ts.end());

        int i = 0;
        while (i < s.length()) {
            if (ss[i] != ts[i]) {
                return ts[i];
            }
            i++;
        }

        return ts[i];
    }
};