class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        long long int i = 0, j = 0, n = nums.size(), ans = 0, count = 0;

        for(; j < n; j++){
            count += nums[j] == 0;

            while(count > 1) count -= nums[i++] == 0;

            ans = max(ans, j - i);
        }

        return ans;
    }
};