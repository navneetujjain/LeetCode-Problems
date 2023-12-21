class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.size(), ans = 0;

        for(int i = 1; i <= 26; i++){
            int len = i * k;

            if(len > n) break;

            vector<int> freq(26, 0);

            int count_freq = 0, l = 0, r = 0;

            while(r < n){
                if((r > 0) && (abs(word[r - 1] - word[r]) > 2)){
                    fill(freq.begin(), freq.end(), 0);
                    count_freq = 0;
                    l = r;
                }

                if(freq[word[r] - 'a'] == k) count_freq--;

                freq[word[r] - 'a']++;

                if(freq[word[r] - 'a'] == k) count_freq++;

                if((r - l + 1) > len){
                    if (freq[word[l] - 'a'] == k) count_freq--;
                    freq[word[l] - 'a']--;
                    if (freq[word[l] - 'a'] == k) count_freq++; 
                    l++;
                }

                if (((r - l + 1) == len) && (count_freq == i)) ans++;

                r++;
            }
        }

        return ans;
    }
};