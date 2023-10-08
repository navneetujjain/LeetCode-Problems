class Solution {
public:
    int f(vector<int>& nums1, vector<int>& nums2, int n, int m, vector<vector<int>> &dp){
        if(n < 0 || m < 0) return INT_MIN;

        if(dp[n][m] != -1) return dp[n][m];

        return dp[n][m] = max(nums1[n] * nums2[m] + max(f(nums1, nums2, n - 1, m - 1, dp), 0), max(f(nums1, nums2, n - 1, m, dp), f(nums1, nums2, n, m - 1, dp)));


    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return f(nums1, nums2, n - 1, m - 1, dp);
    }
};