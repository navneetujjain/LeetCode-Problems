class Solution {
public:
    int f(string s, int ind, vector<int> &dp){
        if(ind == s.size()) return 1;

        if(s[ind] =='0') return 0;

        if(ind == s.size() - 1) return 1;

        if(dp[ind] != -1) return dp[ind];

        string a = s.substr(ind, 2);

        int onestep = f(s, ind + 1, dp);
        int twostep = 0;

        if(stoi(a) <= 26 && stoi(a) > 0) twostep = f(s, ind + 2, dp);

        return dp[ind] = onestep + twostep;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, -1);
        int ans = 0;

        ans = f(s, 0, dp);

        return ans;
    }
};