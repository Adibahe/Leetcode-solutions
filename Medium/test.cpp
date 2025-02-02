#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> output;
        map<string, vector<string>> table;

        int j = 0;
        while(j < strs.size()){
            string temp = strs[j];
            sort(temp.begin(), temp.end());

            table[temp].push_back(strs[j]);
            j++;
        }
        j = 0;
        while(j < strs.size()){
            string temp = strs[j];
            sort(temp.begin(), temp.end());

            output.push_back(table[temp]);
            j++;
        }
        return output;
    }
};

int main(){
    vector<string> collection = {"abc","a","z","bcd", "xyz","az","ba","acef"};
    sort(collection.begin(), collection.end());
    for(string e : collection){
        cout << e << endl;
    }
    return 0;
}