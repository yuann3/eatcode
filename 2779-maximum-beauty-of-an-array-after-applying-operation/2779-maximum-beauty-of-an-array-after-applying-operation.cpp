class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxBeauty = 1;
        for (int target = 1; target <= 100000; target++) {
            int count = 0;
            for (int num : nums) {
                if (target >= num - k && target <= num + k) {
                    count++;
                }
            }
            maxBeauty = max(maxBeauty, count);
        }
        return maxBeauty;
    }
};
