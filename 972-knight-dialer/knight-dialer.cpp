class Solution {
public:
    const int MOD = 1e9 + 7;
    int knightDialer(int n) {
        vector<vector<int>>moves{{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{1,7,0},{2,6},{1,3},{4,2}};
        vector<vector<int>> dp(10, vector<int> (n + 1, 0));
        
        int ans = 0;
        for(int i = 0; i < 10; i++){
            dp[i][1] = 1;
        }

        if(n == 1) return 10;

        for(int i = 2; i <= n; i++){
            for(int j = 0; j < 10; j++){
                for(int k = 0; k < moves[j].size(); k++){
                    dp[j][i] = (dp[j][i] + dp[moves[j][k]][i - 1]) % MOD;
                }
            }
        }

        

        for(int i = 0; i < 10; i++) {
            ans = (ans + dp[i][n]) % MOD;
        }

        return ans;


    }
};