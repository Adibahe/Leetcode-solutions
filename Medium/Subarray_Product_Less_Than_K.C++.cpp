// Solution for Subarray Product Less Than K in C++ 
// This file contains the code for the problem: Subarray Product Less Than K 
// Topic: Array 
// Language: C++ 
 
// Your code here... 
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;

    int product = 1;
    int left = 0;
    int count = 0;

    for (int right = 0; right < nums.size(); ++right) {
        product *= nums[right];

        while (product >= k && left <= right) {
            product /= nums[left];
            ++left;
        }

        count += (right - left + 1);
    }

    return count;
}
};