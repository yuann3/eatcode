class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
           return 0;
        }
        sort(nums.begin(), nums.end());

        int maxLength = 1;
        int currentLength = 1;

        for (int i = 1; i < nums.size(); i++) {
            // if current num equal to previous, then skip
            if (nums[i] == nums[i - 1]) {
                continue;
            }

            // if current num is consecutive
            if (nums[i] == nums[i - 1] + 1) {
                currentLength++;
                maxLength = max(maxLength, currentLength);
            } else {
                currentLength = 1;
            }
        }
        return maxLength;
    }
};