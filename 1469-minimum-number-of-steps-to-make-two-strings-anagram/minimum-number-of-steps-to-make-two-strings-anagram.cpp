class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int, int> mpp;
        int count = 0;

        for(auto it : s){
            mpp[it]++;
        }

        for(auto it : t){
            mpp[it]--;
        }

        for(auto it : mpp){
            if(it.second > 0) count += it.second;
        }

        return count;
    }
};