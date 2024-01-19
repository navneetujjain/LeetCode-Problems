class Solution {
public:
    /*int f(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
      if(m < 0 || m >= grid.size()) return 1e8;
      if(n == 0) return grid[n][m];

      if(dp[n][m] != -1) return dp[n][m];

      int up = grid[n][m] + f(n - 1, m, grid, dp);
      int leftd = grid[n][m] + f(n - 1, m - 1, grid, dp);
      int rightd = grid[n][m] + f(n - 1, m + 1, grid, dp);

      return dp[n][m] = min(up, min(leftd, rightd));
    }*/

    //Tabulation because Memoization Chal ni raha :(
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) dp[0][i] = matrix[0][i];

        for(int i = 1; i < n; i++){
          for(int j = 0; j < n; j++){
            int leftd = 1e9, rightd = 1e9;

            int up = matrix[i][j] + dp[i - 1][j];

            if(j - 1 >= 0) leftd = matrix[i][j] + dp[i -1][j - 1];

            if(j + 1 < n) rightd = matrix[i][j] + dp[i - 1][j + 1];

            dp[i][j] = min(up, min(leftd, rightd));
          }
        }

        int maxi = dp[n - 1][0];

        for(int j = 1; j < n; j++) maxi = min(maxi, dp[n-1][j]);

        return maxi;
    }
};