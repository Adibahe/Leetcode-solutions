// Solution for Max Consecutive Ones III in C++ 
// This file contains the code for the problem: Max Consecutive Ones III 
// Topic: Array 
// Language: C++ 
 
// Your code here... 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int window = 0, max = 0,or_k = k;

        for(int i=0; i < nums.size();i++){

            if(nums.at(i) == 0)
            {
                if(k > 0){ k--; window ++;}

                else if(k == 0 && window > 0){
                    window --;
                    i--;

                    if(nums.at(i - window) == 0 && k <= or_k) k++;
                }
            }
            else window ++;
            

            if(max < window) max = window;

        }

        return max;

    }
};