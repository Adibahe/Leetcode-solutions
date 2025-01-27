// Solution for Maximum Sum of Distinct Subarrays With Length K in C++ 
// This file contains the code for the problem: Maximum Sum of Distinct Subarrays With Length K 
// Topic: Array 
// Language: C++ 
 
// Your code here... 
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, long long k) {
        long long sum = 0, max = 0, count = 0;
        map<long long,long long> table;

        for(long long i = 0, j = 0; j < nums.size();j++){
            auto it = table.find(nums.at(j));

            sum += nums.at(j);
            table[nums.at(j)] ++;

            if(j - i >= k){
                sum -= nums.at(i);
                if((table[nums.at(i)] --) <= 0) table.erase(nums.at(i));
                i++;
            }
            count ++;
            if(max < sum && table.size() == k) max = sum;
        }
        return max;
    }
};