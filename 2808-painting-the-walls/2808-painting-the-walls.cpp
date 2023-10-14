class Solution {
public:
    int f(vector<int> &cost, vector<int> &t, int n, int time, vector<vector<int>> &dp){
        if(time <= 0) return 0;

        if(n < 0) return 1e9;

        if(dp[n][time] != -1) return dp[n][time];

        int take = cost[n] + f(cost, t, n - 1, time - t[n] - 1, dp);
        int nottake = 0 + f(cost, t, n - 1, time, dp);

        return dp[n][time] = min(take, nottake);

    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return f(cost, time, n - 1, n, dp);
    }
};