class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = (int)nums.size();
        
        vector<int> parityBits((n + 31) / 32, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                parityBits[i / 32] |= (1 << (i % 32));
            }
        }

        vector<int> invalid(n, 0);
        for (int i = 1; i < n; i++) {
            bool currParity = (parityBits[i / 32] >> (i % 32)) & 1;
            bool prevParity = (parityBits[(i - 1) / 32] >> ((i - 1) % 32)) & 1;
            if (currParity == prevParity) {
                invalid[i] = 1;
            }
        }

        // Prefix sum of invalid array
        // prefixInvalid[i] = sum of invalid[j] for j <= i
        vector<int> prefixInvalid(n, 0);
        for (int i = 1; i < n; i++) {
            prefixInvalid[i] = prefixInvalid[i - 1] + invalid[i];
        }

        // For each query, we need to check if the subarray [start..end] is special.
        // The subarray is special if there are no positions i in [start+1..end] where invalid[i] = 1.
        // Using prefix sums:
        // invalidCount = prefixInvalid[end] - prefixInvalid[start]
        // If invalidCount == 0, the subarray is special.
        
        vector<bool> answer;
        answer.reserve(queries.size());
        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];
            
            int invalidCount = (end > start) ? prefixInvalid[end] - prefixInvalid[start] : 0;
            answer.push_back(invalidCount == 0);
        }

        return answer;
    }
};
