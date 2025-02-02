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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0, j = 0;
        vector<int> store;
        set<int> table;

        while(j < nums.size()){
            auto it = table.find(nums[j]);
            if(it != table.end()) return true;
            else table.insert(nums[j]);

            if(j - i < k) j++;
            else if(j - i == k){
                j++;
                table.erase(nums[i]);
                i++;
            }
        }
        return false;
    }
};