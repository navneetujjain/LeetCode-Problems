class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> ans;

        for(int i = 0; i < strs.size(); i++){
            string k = strs[i];
            sort(k.begin(), k.end());
            mpp[k].push_back(strs[i]);
        } 

        for(auto it: mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};