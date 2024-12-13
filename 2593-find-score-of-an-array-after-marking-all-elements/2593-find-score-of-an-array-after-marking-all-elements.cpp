class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();

        set<pair<int,int>> elements;
        for (int i = 0; i < n; i++) {
            elements.insert({nums[i], i});
        }

        long long score = 0;
        vector<bool> marked(n, false);
        while (!elements.empty()) {
            auto [val, idx] = *elements.begin();
            elements.erase(elements.begin());
            
            if (marked[idx]) continue;
            
            score += val;
            marked[idx] = true;
            
            if (idx > 0) {
                marked[idx-1] = true;
                elements.erase({nums[idx-1], idx-1});
            }
            if (idx < n-1) {
                marked[idx+1] = true;
                elements.erase({nums[idx+1], idx+1});
            }
        }
        
        return score;
    }
};