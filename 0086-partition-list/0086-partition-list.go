/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func partition(head *ListNode, x int) *ListNode {
    lessHead := &ListNode{Val: 0}
    greaterEqualHead := &ListNode{Val: 0}

    lessTail := lessHead
    greaterEqualTail := greaterEqualHead

    // Iterate through the original list
    for head != nil {
        if head.Val < x {
            // Append to the less_than list
            lessTail.Next = head
            lessTail = head
        } else {
            // Append to the greater_equal list
            greaterEqualTail.Next = head
            greaterEqualTail = head
        }
        head = head.Next // Move to the next node in the original list
    }

    lessTail.Next = greaterEqualHead.Next // Connect less_than to greater_equal
    greaterEqualTail.Next = nil           // Terminate the greater_equal list

    return lessHead.Next // Return the head of the partitioned list
}

func createLinkedList(nums []int) *ListNode {
    if len(nums) == 0 {
        return nil
    }
    head := &ListNode{Val: nums[0]}
    current := head
    for i := 1; i < len(nums); i++ {
        current.Next = &ListNode{Val: nums[i]}
        current = current.Next
    }
    return head
}

func linkedListToSlice(head *ListNode) []int {
    result := []int{}
    for head != nil {
        result = append(result, head.Val)
        head = head.Next
    }
    return result
}
