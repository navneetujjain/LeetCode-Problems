class Solution {
public:
    const int MOD = 1e9 + 7;

    int f(int n, int k, int target, vector<vector<int>>&dp){
        if(n == 0){
            if(target == 0) return 1;
            else return 0;
        }

        if(target < 0) return 0;

        if(dp[n][target] != -1) return dp[n][target];

        int ways = 0;

        for(int i = 1; i <= k; i++){
            ways = ((ways % MOD) + (f(n - 1, k, target - i, dp) % MOD)) % MOD;
        }
        
        return dp[n][target] = ways % MOD;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return f(n, k, target, dp);
    }
};