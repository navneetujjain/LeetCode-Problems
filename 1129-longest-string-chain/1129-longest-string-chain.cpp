class Solution {
public:
    bool isPos(string &s1, string &s2){
        if(s1.size() != s2.size() + 1) return false;

        int i = 0, j = 0;

        while(i < s1.size()){
            if(j < s2.size() && s1[i] == s2[j]){
                i++;
                j++;
            }
            else i++;
        }

        if(i == s1.size() && j == s2.size()) return true;

        return false;
    }
    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin(), arr.end(), comp);
        int n = arr.size(), maxi = 1;
        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isPos(arr[i], arr[j])) dp[i] = max(dp[i], 1 + dp[j]);
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
        
    }
};