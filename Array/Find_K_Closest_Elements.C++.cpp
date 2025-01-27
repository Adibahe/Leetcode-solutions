// Solution for Find K Closest Elements in C++ 
// This file contains the code for the problem: Find K Closest Elements 
// Topic: Array 
// Language: C++ 
 
// Your code here... 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0, j = arr.size() - 1;
        vector<int> result;
        while(j - i  >= k){
            if(abs(arr[i]- x) > abs(arr[j] - x)) i++;
            else j--;
        }
        while(i <= j){
            result.push_back(arr[i]);
            i++;
        }
        return result;
    }
};