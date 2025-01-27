// Solution for Number of Sub-arrays With Odd Sum in C++ 
// This file contains the code for the problem: Number of Sub-arrays With Odd Sum 
// Topic: Array 
// Language: C++ 
 
// Your code here... 
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long evensum = 1, oddsum = 0, prefixsum = 0, count = 0;

        for(int dummy : arr){
            prefixsum += dummy;

            if(prefixsum % 2 == 0) {evensum += 1; count += oddsum;}
            else {oddsum += 1; count += evensum;}
        }
        return count % 1000000007;
    }
};

