class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<long> freq(26, 0);
        for(char c : s) {
            freq[c - 'a']++;
        }
        
        string result;
        priority_queue<pair<int, long>> pq; 
        
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                pq.push({i, freq[i]});
            }
        }
        
        while(!pq.empty()) {
            auto [idx1, cnt1] = pq.top();
            pq.pop();
            
            int charsToAdd = min((long)repeatLimit, cnt1);
            
            result.append(charsToAdd, 'a' + idx1);
            cnt1 -= charsToAdd;
            
            if(cnt1 > 0 && !pq.empty()) {
                auto [idx2, cnt2] = pq.top();
                pq.pop();
                
                result += ('a' + idx2);
                cnt2--;
                
                if(cnt2 > 0) {
                    pq.push({idx2, cnt2});
                }
                pq.push({idx1, cnt1});
            }
            else if(cnt1 > 0) {
                break;
            }
        }
        
        return result;
    }
};
