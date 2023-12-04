class Solution {
public:
    bool f(string x){
        for(int i = 0; i < 2; i++){
            if(x[i] != x[i + 1]) return false;
        }

        return true;
    }
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.size();
        if(num.size() < 3) return ans;

        for(int i = 0; i < n - 2; i++){
            string x = num.substr(i, 3);
            if(f(x)){
                ans = max(ans, x);
            }
        }

        return ans;
    }
};