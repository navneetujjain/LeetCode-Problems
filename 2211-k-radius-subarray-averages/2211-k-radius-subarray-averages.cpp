class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        int windowsize = 2 * k + 1;
        long long sum = 0;

        vector<int> ans(n, -1);

        if(n < windowsize) return ans;

        for(int i = 0; i < n; i++){
            sum += nums[i];

            if(i - windowsize >= 0) {
                sum -= nums[i - windowsize];
            }

            if(i >= windowsize - 1){
                ans[i - k] = sum/windowsize;
            }
        }

        return ans;
    }
};