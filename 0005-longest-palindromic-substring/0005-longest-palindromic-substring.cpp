class Solution {
private:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }
    
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLength = 1;
        
        for (int i = 0; i < s.length(); i++) {
            pair<int, int> odd = expandAroundCenter(s, i, i);
            int length1 = odd.second - odd.first + 1;
            if (length1 > maxLength) {
                start = odd.first;
                maxLength = length1;
            }
            
            pair<int, int> even = expandAroundCenter(s, i, i + 1);
            int length2 = even.second - even.first + 1;
            if (length2 > maxLength) {
                start = even.first;
                maxLength = length2;
            }
        }
        
        return s.substr(start, maxLength);
    }
};
