class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        vector<int> ans;

        for(auto it : nums1) mpp[it]++;

        for(auto it : nums2){
            if(mpp.find(it) != mpp.end()){
                if(mpp[it] != -1){
                    mpp[it] = -1;
                    ans.push_back(it);
                }
            }
        }

        return ans;
    }
};