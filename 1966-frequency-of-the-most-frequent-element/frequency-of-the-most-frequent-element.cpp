class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
         long long j = 0, n = nums.size(), ans = 1, sum = 0;

         for(int i = 0; i < n; i++){
            sum += nums[i];

            while((i - j + 1) * nums[i] - sum > k) sum -= nums[j++];

            ans = max(ans, i - j + 1);
         }

         return ans;
    }
};