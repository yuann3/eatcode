impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let n = nums.len();
        if n <= 2 {
            return n as i32;
        }

        let mut k = 2;
        for i in 2..n {
            if nums[i] != nums[k-2] {
                nums[k] = nums[i];
                k += 1;
            }
        }

        k as i32
    }
}