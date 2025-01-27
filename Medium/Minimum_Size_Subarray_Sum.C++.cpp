// Solution for Minimum Size Subarray Sum in C++ 
// This file contains the code for the problem: Minimum Size Subarray Sum 
// Topic: Array 
// Language: C++ 
 
// Your code here... 
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        for(int i = 1 ; i < nums.size(); i++){
            nums.at(i) += nums.at(i - 1);
        }
        
        int window = 0,min = 0;
        bool looking = true;

        for(int i = 0; i < nums.size();){
            if(looking)
            {  window ++;
            
                if(target <= nums.at(i))
                {
                    looking = false;

                    if(window == 1) return window;
                    else if(window > 1){
                        min = window;
                        window --;
                    }
                }
                else
                    i++;
            }
            else{
                if(target <= nums.at(i) - nums.at(i - window)){
                    min = window;
                    window --;
                }
                else
                    i++;
            }

        }

        return min;

    }
};