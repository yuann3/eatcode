class Solution {
public:
    string makeFancyString(string s) {
        if(s.length() <= 2) return s;
        
        int writeIndex = 2; 
        
        for(int readIndex = 2; readIndex < s.length(); readIndex++) {
            if(s[writeIndex-2] == s[writeIndex-1] && 
               s[writeIndex-1] == s[readIndex]) {
                continue;
            }
            s[writeIndex++] = s[readIndex];
        }
        
        return s.substr(0, writeIndex);
    }
};
