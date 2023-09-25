class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int i = 0, j = 0;

        char ans = '1';
        while(i < s.size()){
            if(s[i] != t[j]){
                ans = t[j];
                break;
            }
            i++;
            j++;
        }

        if(ans == '1') ans = t[t.size() - 1];
        return ans;
    }
};