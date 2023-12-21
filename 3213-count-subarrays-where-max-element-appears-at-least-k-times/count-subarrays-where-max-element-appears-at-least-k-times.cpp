class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int maxi = 0, left;
        
        for(auto it : nums) maxi = max(maxi, it);

        unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == maxi) mpp[maxi]++;

            while(mpp[maxi] >= k){
                ans += nums.size() - i;

                if(nums[left] == maxi) mpp[maxi]--;

                left++;
            }

        }
        
        return ans;
    }
};