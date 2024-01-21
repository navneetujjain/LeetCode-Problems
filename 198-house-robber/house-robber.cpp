class Solution {
public:
    vector<int> dp;
    int f(vector<int> &nums, int index){
        if(index < 0) return 0;

        if(dp[index] != -1) return dp[index];

        int take = nums[index] + f(nums, index - 2);
        int nottake = 0 + f(nums, index - 1);

        return dp[index] = max(take, nottake);
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size() + 1, -1);

        return f(nums, nums.size() - 1);
    }
};