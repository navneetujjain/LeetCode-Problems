class Solution {
public:
    vector<int> dp;
    /*int f(int n){
        if(n < 0) return 0;
        if(n == 0) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = f(n - 1) + f(n - 2);
    }*/
    int climbStairs(int n) {
        dp.resize(n + 1, -1);
        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            dp[i] = dp[i - 1];
            if(i > 1) dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};