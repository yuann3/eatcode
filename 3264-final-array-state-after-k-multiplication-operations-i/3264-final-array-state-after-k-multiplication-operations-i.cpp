class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> result = nums;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        for(int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        
        for(int i = 0; i < k; i++) {
            auto [val, idx] = pq.top();
            pq.pop();
            
            val *= multiplier;
            result[idx] = val;
            
            pq.push({val, idx});
        }
        
        return result;
    }
};