class Solution {
public:
    string compressedString(string word) {
        string comp;
        int i = 0;

        while (i < word.length()) {
            char current = word[i];
            int count = 0;

            while (i < word.length() && word[i] == current && count < 9) {
                count++;
                i++;
            }
            comp += to_string(count) + current;
        }

        return comp;
    }
};