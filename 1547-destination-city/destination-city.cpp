class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mpp;

        for(auto it : paths) mpp[it[0]]--, mpp[it[1]]++;

        for(auto it : mpp){
            if(it.second == 1) return it.first;
        }

        return "";
    }
};