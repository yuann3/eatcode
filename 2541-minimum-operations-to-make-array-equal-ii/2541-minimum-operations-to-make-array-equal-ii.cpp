class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) {
            return nums1 == nums2 ? 0 : -1;
        }
        
        int n = nums1.size();
        long long pos_diff = 0;
        long long total_diff = 0;
        
        for (int i = 0; i < n; i++) {
            long long diff = (long long)nums1[i] - nums2[i];
            
            if (diff != 0 && k != 0 && diff % k != 0) {
                return -1;
            }
            
            total_diff += diff;
            if (diff > 0) {
                pos_diff += diff;
            }
        }

        if (total_diff != 0) {
            return -1;
        }
        
        return pos_diff / k;
    }
};