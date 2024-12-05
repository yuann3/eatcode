class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        vector<pair<char, int>> s_pieces, t_pieces;

        for (int i = 0; i < n; i++) {
            if (start[i] != '_')
                s_pieces.push_back({start[i], i});
            if (target[i] != '_')
                t_pieces.push_back({target[i], i});
        }

        if (s_pieces.size() != t_pieces.size())
            return false;

        for (int i = 0; i < s_pieces.size(); i++) {
            if (s_pieces[i].first != t_pieces[i].first)
                return false;

            char pieces = s_pieces[i].first;
            int s_pos = s_pieces[i].second;
            int t_pos = t_pieces[i].second;

            if (pieces == 'L' && s_pos < t_pos)
                return false;
            if (pieces == 'R' && s_pos > t_pos)
                return false;
        }

        return true;
    }
};