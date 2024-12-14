use std::collections::VecDeque;
impl Solution {
    pub fn continuous_subarrays(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut result = 0i64;
        let mut left = 0;
        let mut max_deque: VecDeque<usize> = VecDeque::new();
        let mut min_deque: VecDeque<usize> = VecDeque::new();

        for right in 0..n {
            while !max_deque.is_empty() && 
                    nums[*max_deque.back().unwrap()] <= nums[right] {
                max_deque.pop_back();
            }
            max_deque.push_back(right);

            while !min_deque.is_empty() && 
                    nums[*min_deque.back().unwrap()] >= nums[right] {
                min_deque.pop_back();
            }
            min_deque.push_back(right);
            
            while !max_deque.is_empty() && !min_deque.is_empty() && 
                    nums[*max_deque.front().unwrap()] - nums[*min_deque.front().unwrap()] > 2 {
                left += 1;
                
                while !max_deque.is_empty() && *max_deque.front().unwrap() < left {
                    max_deque.pop_front();
                }
                while !min_deque.is_empty() && *min_deque.front().unwrap() < left {
                    min_deque.pop_front();
                }
            }
            
            result += (right - left + 1) as i64;
        }
        
        result
    }
}