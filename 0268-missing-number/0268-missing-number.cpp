class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = n * (n + 1) / 2;

        int curr = 0;
        for(auto it : nums) curr += it;

        return sum - curr; 
    }
};