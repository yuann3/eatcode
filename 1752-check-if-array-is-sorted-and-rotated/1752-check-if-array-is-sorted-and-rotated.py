class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        for i in range(n):
            rotated = nums[i:] + nums[:i]
            if all(rotated[j] <= rotated[j+1] for j in range(n-1)):
                return True
        return False