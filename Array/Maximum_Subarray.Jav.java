// Solution for Maximum Subarray in Java 
// This file contains the code for the problem: Maximum Subarray 
// Topic: Array 
// Language: Java 
 
// Your code here... 
class Solution {
    public int maxSubArray(int[] arr) {
        int max = Integer.MIN_VALUE;
        int current=0;
        for (int i = 0; i < arr.length; i++) {
            if (current + arr[i] > arr[i]) {
                current += arr[i];
            } else
                current = arr[i];

            if (max < current)
                max = current;
        }
        return max;
    }
}