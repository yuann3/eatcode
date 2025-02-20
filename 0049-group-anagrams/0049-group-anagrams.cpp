class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (auto s : strs) {
            string word = s;
            std::sort(word.begin(), word.end());
            map[word].push_back(s);
        } 

        vector<vector<string>> result;
        for (auto ans : map) {
            result.push_back(ans.second);
        }
        return result;
    }
};