class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = 0, n = nums.size();
        vector<int> ans(n), prefix(n), suffix(n);
        

        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + nums[i];
            suffix[n - i - 1] = suffix[n - i] + nums[n - i - 1];
        }

        for(int i = 0; i < n; i++){
            int x = ((nums[i] * i) - prefix[i]) + (suffix[i] - (nums[i] * (n - i - 1)));
            ans[i] = x;
        }

        return ans;
    }
};