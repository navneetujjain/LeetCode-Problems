class Solution {
public:
    vector<int> dp;
    int f(int n){
        if(n < 0) return 0;
        if(n == 0) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = f(n - 1) + f(n - 2);
    }
    int climbStairs(int n) {
        dp.resize(n + 1, -1);

        return f(n);
    }
};