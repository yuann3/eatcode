class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();

        if (n2 > n1) {
            return false;
        }

        int i = 0;
        int j = 0;

        while (i < n1 && j < n2) {
            char nextChar = (str1[i] - 'a' + 1) % 26 + 'a';

            if (str1[i] == str2[j] || nextChar == str2[j]) {
                j++;
            }
            i++;
        }

        return j == n2;
    }
};