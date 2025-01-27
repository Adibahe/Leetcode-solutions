// Solution for Divide Players Into Teams of Equal Skill in C++ 
// This file contains the code for the problem: Divide Players Into Teams of Equal Skill 
// Topic: Array 
// Language: C++ 
 
// Your code here... 
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

    sort(skill.begin(), skill.end());
    int len = skill.size(), prev = 0, current = 0 ;
    long sumOfChemistry = 0;

    for(int i=0; i < len/2; i++){
        current = skill[i] + skill[len - i -1];

        sumOfChemistry += (skill[i] * skill[len - i - 1]);

        if(prev != current && i != 0)
            return -1;
        else
            prev = current;
    }
    return sumOfChemistry;
}
};