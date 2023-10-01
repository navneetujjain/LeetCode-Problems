class Solution {
public:
    string reverseWords(string s) {
        //reverse(s.begin(), s.end());
        string ans = "", dummy = "";
        for(int i = 0; i <= s.size(); i++){
            if(s[i] == ' ' || i == s.size()){
                reverse(dummy.begin(), dummy.end());
                ans += dummy + " ";
                dummy = "";
            }
            else dummy += s[i];
        }

        ans.pop_back();
        return ans;
    }
};