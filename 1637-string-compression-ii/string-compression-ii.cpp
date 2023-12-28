int dp[101][101][27][101];
class Solution {
public:
    
    int f(int index, int k, int prev, int prev_count, string &s){
        if(k < 0) return 1e9;

        if(index == s.size()) return 0;

        if(dp[index][k][prev][prev_count] != -1) return dp[index][k][prev][prev_count];

        int nottake = 0 + f(index + 1, k - 1, prev, prev_count, s);
        int take = 0;

        if(s[index] == (prev + 'a')){
            take = f(index + 1, k, prev, prev_count + 1, s);
            take += (prev_count == 1 || prev_count == 9 || prev_count == 99);
        }
        else take = 1 + f(index + 1, k, s[index] - 'a', 1, s);

        return dp[index][k][prev][prev_count] = min(take, nottake);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return f(0, k, 26, 0, s);
    }
};