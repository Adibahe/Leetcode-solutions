// Solution for Search a 2D Matrix in Java 
// This file contains the code for the problem: Search a 2D Matrix 
// Topic: Array 
// Language: Java 
 
// Your code here... 
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int ele = rows * cols, mid = 0, start = 0, end;
        end = ele - 1;

        while (true) {
            if (start <= end) {
                mid = (start + end) / 2;
                if (matrix[mid / cols][mid % cols] == target)
                    return true;
                else if (target > matrix[mid / cols][mid % cols]) {
                    start = mid + 1;
                } else
                    end = mid - 1;
            } else {
                return false;
            }

        }
    }
}