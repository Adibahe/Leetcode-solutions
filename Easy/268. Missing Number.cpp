class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int s = nums.size()*(nums.size() + 1)/2;
        int sum = 0;
        for(int e: nums) sum += e;

        return abs(sum - s);
    }
};