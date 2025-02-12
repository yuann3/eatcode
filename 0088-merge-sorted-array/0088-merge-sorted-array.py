class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Merge nums2 into nums1 as one sorted array.
        Do not return anything, modify nums1 in-place instead.
        """
        p1 = m - 1       # Last index of initial elements in nums1
        p2 = n - 1       # Last index of nums2
        p = m + n - 1    # Last position in nums1

        # While there are still elements in nums2
        while p2 >= 0:
            # Check if there are remaining elements in nums1 and if the current element in nums1 is larger
            if p1 >= 0 and nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1
            p -= 1
