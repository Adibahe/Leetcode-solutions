#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> table;
        int i = 0;
        if(s.size() != t.size()) return false;
        while(i < s.size()){
            table[s[i]]++;
            i++;
        }
        i = 0;
        while(i < t.size()){
            auto it = table.find(t[i]);
            if(it != table.end()){ 
                table[t[i]]--;
                if(table[t[i]] == 0) table.erase(t[i]);
            }
            else table[t[i]]++;
            i++;
        }
        if(table.size() > 0) return false;
        return true;
    }
};