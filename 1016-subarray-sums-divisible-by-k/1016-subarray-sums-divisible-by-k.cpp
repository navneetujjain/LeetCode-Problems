class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, count = 0;

        unordered_map<int, int> mpp;

        mpp[sum]++;

        for(int i = 0; i < nums.size(); i++){
            sum = (sum + nums[i]) % k;

            if(sum < 0) sum += k;

            count += mpp[sum];

            mpp[sum]++;
        }

        return count;
    }
};