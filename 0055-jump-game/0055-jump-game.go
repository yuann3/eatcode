func canJump(nums []int) bool {
    maxReach := 0

    for i := 0; i <= maxReach && i < len(nums); i++ {
        if maxReach < i + nums[i] {
            maxReach = i + nums[i]
        }

        if maxReach >= len(nums) - 1 {
            return true
        }
    }

    return maxReach >= len(nums) - 1
}