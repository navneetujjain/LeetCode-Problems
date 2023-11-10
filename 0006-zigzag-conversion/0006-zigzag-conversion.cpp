class Solution {
public:
    string convert(string s, int n) {
        if(n <= 1) return s;

        vector<string> v(n, "");

        int j = 0, dir = -1;

        for(int i = 0; i < s.size(); i++){
            if(j == n - 1 || j == 0) dir = dir * -1;

            v[j] += s[i];

            if(dir == 1) j++;

            else j--;
        }

        string ans = "";

        for(auto it : v) ans +=  it;

        return ans;
    }
};