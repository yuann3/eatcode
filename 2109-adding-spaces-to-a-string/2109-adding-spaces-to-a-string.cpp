class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int spaceCount = spaces.size();
        string result;
        result.reserve(s.size() + spaceCount); 

        int currentIndex = 0;
        int spaceIndex = 0;

        while (currentIndex < s.length()) {
            if (spaceIndex < spaces.size() && currentIndex == spaces[spaceIndex]) {
                result += ' '; 
                spaceIndex++;
            }

            result += s[currentIndex];
            currentIndex++;
        }
        
        return result;
    }
};