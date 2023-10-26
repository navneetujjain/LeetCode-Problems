class Solution {
public:
    const int MOD = 1e9 + 7;

    long long f(vector<int> &arr, int index, unordered_map<int, int> &mpp, vector<int> &dp){
        if(index < 0){
            return 0;
        }

        if(dp[index] != -1) return dp[index];

        long long ans = 1;

        for(int i = 0; i < index; i++){
            if(arr[index] % arr[i] == 0 && mpp.find(arr[index]/arr[i]) != mpp.end()){
                long long int left = f(arr, i, mpp, dp);
                long long int right = f(arr, mpp[arr[index]/ arr[i]], mpp, dp);

                ans += (left * right) % MOD;
            }
        }

        return dp[index] = ans % MOD;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, int> mpp;
        int n = arr.size(), res = 0;

        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            mpp[arr[i]] = i;
        }

        for(int i = n - 1; i >= 0; i--){
            vector<int> dp(n + 1, -1);
            res = (res + (int)f(arr, i, mpp, dp)) % MOD;
        }

        return res;
    }
};