class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = s.size(), m = 0;
        int k = t.size(), n = 0;
        while(m < l && n < k){
            if(s[m] == t[n]){
                m++;
                n++;
            }

            else n++;
        }

        if(m == l) return true;

        return false;
    }
};