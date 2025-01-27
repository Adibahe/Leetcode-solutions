// Solution for Rotate Array in Java 
// This file contains the code for the problem: Rotate Array 
// Topic: Array 
// Language: Java 
 
// Your code here... 
class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;
        nums = reverse(nums, 0, n - 1);
        nums = reverse(nums, 0, k - 1);
        nums = reverse(nums, k, n - 1 + (k));

        for (int e : nums) {
            System.out.print(e + " ");
        }
    }

    public int[] reverse(int[] nums, int i, int j) {
        if(j == -1 )
            j=0;
        for (int k = i; k <= j / 2; k++) {
            int temp = nums[k];
            nums[k] = nums[j - k];
            nums[j - k] = temp;
        }
        return nums;
    }
}