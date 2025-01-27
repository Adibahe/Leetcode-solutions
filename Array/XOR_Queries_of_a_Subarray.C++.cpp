
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        vector<int> ans;

        for(int i = 1; i < arr.size(); i++)
            arr.at(i) ^= arr.at(i - 1);

        for(int i = 0; i < queries.size(); i++){
            if((queries.at(i)).at(0) > 0)
                ans.push_back(arr.at((queries.at(i)).at(0)-1) ^ arr.at((queries.at(i)).at(1)));
            else
                ans.push_back(arr.at((queries.at(i)).at(1)));
        }
        return ans;

    }
};