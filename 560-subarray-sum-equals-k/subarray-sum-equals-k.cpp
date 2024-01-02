class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        int sum = 0, count = 0;
        mpp[0] = 1;
        for(auto it : nums){
            sum += it;
            

            if(mpp.find(sum - k) != mpp.end()){
                count += mpp[sum - k];
            }

            mpp[sum]++;
            
        }

        return count;
    }
};