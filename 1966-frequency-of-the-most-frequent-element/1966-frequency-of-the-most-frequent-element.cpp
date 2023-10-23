class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long int windsum = 0, windsize = 0, maxi = 0, left = 0;

        for(int i = 0; i < nums.size(); i++){
            windsum += nums[i];

            windsize = i - left + 1;

            while(nums[i] * windsize - windsum > k){
                windsum -= nums[left++];
                windsize--;
            }

            maxi = max(maxi, windsize);

        }

        return maxi;
    }
};