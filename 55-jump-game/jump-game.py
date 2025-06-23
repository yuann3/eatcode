class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_index = 0
        for i, jump in enumerate(nums):
            if i > max_index:
                return False
            max_index = max(max_index, i + jump)
            if max_index >= len(nums) - 1:
                return True
        return True