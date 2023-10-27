class Solution {
public:
    string f(string s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            r++;
            l--;
        }

        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            string oddlen = f(s, i, i);
            string evenlen = f(s, i, i + 1);
            if(oddlen.size() > temp.size()) temp = oddlen;
            if(evenlen.size() > temp.size()) temp = evenlen;
        }

        return temp;
    }
};