class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complementMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (complementMap.find(complement) != complementMap.end()) {
                return {complementMap[complement], i};
            }

            complementMap[nums[i]] = i;
        }
        return {};
    }
};