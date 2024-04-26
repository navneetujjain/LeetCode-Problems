class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int mini = 1e9;

        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int j=0; j<n; j++) dp[0][j] = grid[0][j];

        for(int i = 1; i<n; i++) {
            for(int j = 0; j<n; j++) {
                int mini = 1e8;

                for(int k =0; k<n; k++) {
                    if(k!=j) {
                        mini = min(mini, grid[i][j] + dp[i-1][k]);
                    }
                }

                dp[i][j] = mini;
            }
        }

        for(int j=0; j < n; j++) {
            mini = min(mini, dp[n-1][j]);
        }

        return mini;
    }
};