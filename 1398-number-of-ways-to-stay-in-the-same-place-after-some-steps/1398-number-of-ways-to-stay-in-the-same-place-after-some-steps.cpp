class Solution {
public:
    const int MOD = 1e9 + 7;
    int f(int steps, int arrLen, int ind, vector<vector<long long int>> &dp){

        if(ind < 0 || ind >= arrLen || steps < 0) return 0;

        if(steps == 0){
            return ind == 0 ? 1 : 0;
        }

        if(dp[steps][ind] != -1) return dp[steps][ind];

        long long int right = f(steps - 1, arrLen, ind + 1, dp) % MOD;
        long long int left = f(steps - 1, arrLen, ind - 1, dp) % MOD;
        long long int stay = f(steps - 1, arrLen, ind, dp) % MOD;

        return dp[steps][ind] = (left + right + stay) % MOD;
    }
    int numWays(int steps, int arrLen) {
        if(arrLen > steps) arrLen = steps;
        vector<vector<long long int>> dp(steps + 1, vector<long long int>(arrLen + 1, -1));
        return f(steps, arrLen, 0, dp);
    }
};