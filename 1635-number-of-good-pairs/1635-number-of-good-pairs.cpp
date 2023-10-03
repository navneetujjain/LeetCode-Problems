class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> mpp;

        for(auto it : nums) mpp[it]++;

        //int count = 0;
        for(auto it: mpp){
            int n = mpp[it.first];
            count += (n * (n - 1))/2;
        }

        return count;
    }
};