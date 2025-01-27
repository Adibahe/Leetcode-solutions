// Solution for Fruit Into Baskets in C++ 
// This file contains the code for the problem: Fruit Into Baskets 
// Topic: Array 
// Language: C++ 
 
// Your code here... 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0, j = 0, maxlen = 0;
        map<int, int> table;

        while(j < fruits.size()){
            auto it = table.find(fruits[j]);

            if(it != table.end()) { table[fruits[j]]++; j++;}
            else if(table.size() < 2) { table[fruits[j]]++; j++;}
            else {
                table[fruits[i]]--;
                if(table[fruits[i]] == 0) table.erase(fruits[i]);
                i++;
            }
            maxlen = max(maxlen, j-i+1);
            
        }
        return maxlen;
    }
};