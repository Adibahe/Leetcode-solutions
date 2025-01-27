// Solution for Subarray Sum Equals K in C++ 
// This file contains the code for the problem: Subarray Sum Equals K 
// Topic: Array 
// Language: C++ 
 
// Your code here... 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int, int> table = {{0,1}};
        int prefixsum = 0, count = 0;

        for(int value: nums){
            prefixsum += value;

            auto it = table.find(prefixsum - k);
            if(it != table.end()) count += table[prefixsum - k];

            it = table.find(prefixsum);
            if(it == table.end()) table.insert({prefixsum , 1});
            else table[prefixsum] += 1;
        }

        return count;

    }
};