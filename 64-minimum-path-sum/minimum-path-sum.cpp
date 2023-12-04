class Solution {
public:
    int f(int n, int m, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if(n == 0 && m == 0) return grid[0][0];
        if(n < 0 || m < 0) return 1e9;

        if(dp[n][m] != -1) return dp[n][m];

        int up = grid[n][m] + f(n - 1, m, dp, grid);
        int left = grid[n][m] + f(n, m - 1, dp, grid);

        return dp[n][m] = min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return f(n - 1, m - 1, dp, grid);
    }
};