class Solution:
    def distinctNumbers(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        ans = []
        
        freq = {}
        distinct_count = 0
        
        for i in range(k):
            freq[nums[i]] = freq.get(nums[i], 0) + 1
            if freq[nums[i]] == 1:
                distinct_count += 1
        
        ans.append(distinct_count)
        
        for i in range(k, n):
            freq[nums[i-k]] -= 1
            if freq[nums[i-k]] == 0:
                distinct_count -= 1
                
            freq[nums[i]] = freq.get(nums[i], 0) + 1
            if freq[nums[i]] == 1:
                distinct_count += 1
                
            ans.append(distinct_count)
        
        return ans