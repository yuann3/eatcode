class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int n1 = word1.length(), n2 = word2.length();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            result += word1[i++];
            result += word2[j++];
        }
        while (i < n1)
            result += word1[i++];
        while (j < n2)
            result += word2[j++];
        return result;
    }
};