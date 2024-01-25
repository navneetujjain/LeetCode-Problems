class Solution {
public:
    vector<vector<int>> dp;
    int f(string &text1, string &text2, int n, int m){
        if(n < 0 || m < 0) return 0;

        if(dp[n][m] != -1) return dp[n][m];

        int take = 0, nottake = 0;
        if(text1[n] == text2[m]){
            return dp[n][m] = 1 + f(text1, text2, n - 1, m - 1);
        }
        else{
            return dp[n][m] = max(f(text1, text2, n - 1, m), f(text1, text2, n, m - 1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size() + 1, vector<int>(text2.size() + 1, -1));

        int n = text1.size(), m = text2.size();

        return f(text1, text2, n - 1, m - 1);
    }
};