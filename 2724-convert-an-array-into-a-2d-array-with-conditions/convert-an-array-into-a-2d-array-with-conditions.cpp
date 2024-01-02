class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int maxfreq = 0;
        unordered_map<int, int> mpp;
        for(auto it : nums){
            mpp[it]++;

            maxfreq = max(maxfreq, mpp[it]);
        }

        vector<vector<int>> ans;
        while(maxfreq != 0){
            vector<int> temp;
            for(auto it : mpp){
                if(it.second == maxfreq){
                    temp.push_back(it.first);
                    mpp[it.first]--;
                }
            }

            ans.push_back(temp);
            maxfreq--;
        }

        return ans;
    }
};