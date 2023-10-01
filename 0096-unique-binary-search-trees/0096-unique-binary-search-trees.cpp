class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            int ans = 0;
            for(int j = 1; j <= i; j++){
                ans = ans + dp[i - j] * dp[j - 1];
            }
            dp[i] = ans;
        }

        return dp[n];
    }
};