class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(s.begin(), s.end());
        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < s.size(); j++){
                if(s[j] >= g[i]){
                    s[j] = -1;
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};