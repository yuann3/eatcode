class Solution {
public:
    void sortColors(vector<int>& nums) {
        int buckets[3] = {0};

        for (int num : nums) {
            buckets[num]++;
        }
        
        int index = 0;
        for (int i = 0; i < buckets[0]; i++) nums[index++] = 0;
        for (int i = 0; i < buckets[1]; i++) nums[index++] = 1;
        for (int i = 0; i < buckets[2]; i++) nums[index++] = 2;
    }
};