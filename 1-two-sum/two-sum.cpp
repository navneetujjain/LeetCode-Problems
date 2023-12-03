class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }

        for(auto it : mpp){
            int complement = target - it.first;
            if(complement != it.first){
                if(mpp.find(complement) != mpp.end()){
                    return {it.second[0], mpp[complement][0]};
                }
            }
            else{
                if(it.second.size() > 1){
                    return {it.second[0], it.second[1]};
                }
            }
        }

        return {};

    }
};