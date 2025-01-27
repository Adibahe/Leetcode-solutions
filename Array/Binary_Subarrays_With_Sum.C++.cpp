// Solution for Binary Subarrays With Sum in C++ 
// This file contains the code for the problem: Binary Subarrays With Sum 
// Topic: Array 
// Language: C++ 
 
// Your code here... 
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        int sum = 0, count = 0;
        
        for (int num : nums) {
            sum += num;
            if (prefixSumCount.find(sum - goal) != prefixSumCount.end()) {
                count += prefixSumCount[sum - goal];
            }
            prefixSumCount[sum]++;
        }
        
        return count;
    }
};
