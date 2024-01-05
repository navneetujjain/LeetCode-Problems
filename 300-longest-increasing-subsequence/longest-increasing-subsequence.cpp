class Solution {
public:
    int f(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp){
        if(ind == nums.size()) return 0;

        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int take = 0;

        if(prev == -1 || nums[ind] > nums[prev]) take = 1 + f(ind + 1, ind, nums, dp);

        int nottake = 0 + f(ind + 1, prev, nums, dp);

        return dp[ind][prev + 1] = max(take, nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return f(0, -1, nums, dp);    
    }
};