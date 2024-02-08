class Solution {
public:
    int f(int index, vector<int> &dp){
      if(index == 0) return 0;

      if(dp[index] != -1) return dp[index];

      int mini = INT_MAX;

      for(int i = 1; i <= sqrt(index); i++){
        int x = i * i;
        int count = 1 + f(index - x, dp);
        mini = min(mini, count);
      }

      return dp[index]  = mini;
    }
    int numSquares(int n) {
      vector<int> dp(n + 1, -1);
      return f(n, dp); 
    }
};