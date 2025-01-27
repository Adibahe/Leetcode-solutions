// Solution for Product of Array Except Self in C++ 
// This file contains the code for the problem: Product of Array Except Self 
// Topic: Array 
// Language: C++ 
 
// Your code here... 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int size = nums.size();
        int prefix[nums.size()],suffix[nums.size()];
        
        vector<int> ans;

        prefix[0] = nums.at(0);
        suffix[size - 1] = nums.at(size - 1);
        
        for(int i = 1; i<nums.size(); i++){
            prefix[i] = prefix[i - 1] * nums.at(i);
        }
        for(int i = size - 2; i > 0; i--){
            suffix[i] = suffix[i + 1] * nums.at(i);
        }
        for(int i = 0; i < size; i++){
            if(i > 0 && i < size - 1)
                ans.push_back(prefix[i - 1] * suffix[i + 1]);
            else if(i == 0)
                ans.push_back(suffix[i + 1]);
            else if(i == size - 1)
                ans.push_back(prefix[i -1]);
        }

        return ans;
    }
};