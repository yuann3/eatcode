class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complementMap;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(complementMap.find(num) != complementMap.end()) {
                return {complementMap[num], i};
            }
            complementMap[target - num] = i;
        }
        return {};
    }
};