class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i = 0, j = 0, maxi = 0;
        int ans = 1;
        unordered_map<char, int> mpp;
        while(j < n){
            mpp[s[j]]++;
            maxi = max(maxi, mpp[s[j]]);
            if((j - i + 1) - maxi > k){
                mpp[s[i]]--;
                i++;
            }

            ans = max(ans, (j - i + 1));
            j++;
        }

        return ans;
    }
};