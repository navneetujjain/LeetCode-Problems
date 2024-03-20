class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        long long int i = 0, j = 0, n = s.length(), count = 0;
        unordered_map<char, int> mpp;
        for(; j < n; j++){
            mpp[s[j]]++;

            while(mpp[s[j]] > 1){
                mpp[s[i++]]--;
            }

            count = max(count, j - i + 1);
        }

        return count;
    }
};