class Solution {
public:
    int f(int ind, int n, int k, vector<int> &arr, vector<int> &dp){
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int len = 0, maxi = 0, maxAns = INT_MIN;
        for(int i = ind; i < min(n, ind + k); i++){
            len++;
            maxi = max(maxi, arr[i]);
            int ans = (maxi * len) + f(i + 1, n, k, arr, dp);
            maxAns = max(maxAns, ans);
        }

        return dp[ind] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return f(0, arr.size(), k, arr, dp);
    }
};