// Solution for Make Sum Divisible by P in C++ 
// This file contains the code for the problem: Make Sum Divisible by P 
// Topic: Array 
// Language: C++ 
 
// Your code here... 
class Solution {
public:
    int minSubarray(std::vector<int>& nums, int p) {
    int n = nums.size();
    if (n == 0) return -1;

    long long totalSum = 0;
    for (int num : nums) totalSum += num;

    int target = totalSum % p;
    if (target == 0) return 0;  

    std::unordered_map<int, int> prefixMod; 
    prefixMod[0] = -1;  
    long long prefixSum = 0;
    int minLen = n;

    for (int i = 0; i < n; ++i) {
        prefixSum += nums[i];
        int mod = prefixSum % p;

        int needed = (mod - target + p) % p;
        if (prefixMod.find(needed) != prefixMod.end()) {
            minLen = std::min(minLen, i - prefixMod[needed]);
        }

        prefixMod[mod] = i;
    }

    return (minLen == n) ? -1 : minLen;
}
};