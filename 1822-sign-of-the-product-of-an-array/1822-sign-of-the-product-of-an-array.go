func arraySign(nums []int) int {
    negativeCount := 0

    for _, num := range nums {
        if num == 0 {
            return 0
        }
        if num < 0 {
            negativeCount++
        }
    } 

    if negativeCount % 2 == 1 {
        return -1
    }
    return 1
}