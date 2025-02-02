#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string> collection;

        while (ss >> word) collection.push_back(word);

        if (pattern.size() != collection.size()) return false;

        map<char, string> table;
        set<string> usedWords;

        for (int i = 0; i < pattern.size(); i++) {
            if (table.count(pattern[i])) {
                if (table[pattern[i]] != collection[i]) return false;
            } else {
                if (usedWords.count(collection[i])) return false;
                table[pattern[i]] = collection[i];
                usedWords.insert(collection[i]);
            }
        }
        return true;
    }
};
