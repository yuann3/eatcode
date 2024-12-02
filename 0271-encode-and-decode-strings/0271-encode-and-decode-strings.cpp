class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result;
        for (const string& s : strs) {
            result += to_string(s.size()) + '&' + s;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '&') {
               j++; 
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length; 
            result.push_back(s.substr(i, length));
            i = j;
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));