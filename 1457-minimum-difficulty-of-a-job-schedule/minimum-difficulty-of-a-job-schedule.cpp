class Solution {
public:
    int dp[301][1001];
    int f(vector<int> &job, int n, int index, int d){
        if(index == n && d == 0) return 0;

        if(index == n || d == 0 || n < d + index) return 1e9;

        if(dp[index][d] != -1) return dp[index][d];

        int maxi = 0, ans = 1e9;

        for(int i = index; i < n; i++){
            maxi = max(maxi, job[i]);
            int x = f(job, n, i + 1, d - 1);
            if(x != 1e9) ans = min(ans, maxi + x);
        }

        return dp[index][d] = ans;
    }
    int minDifficulty(vector<int>& job, int d) {
        if(job.size() < d) return -1;

        memset(dp, -1, sizeof(dp));

        return f(job, job.size(), 0, d);
    }
};