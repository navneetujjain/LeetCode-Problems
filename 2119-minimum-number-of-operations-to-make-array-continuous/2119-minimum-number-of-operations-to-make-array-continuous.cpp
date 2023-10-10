class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int right = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i + 1 < nums.size() && nums[i] == nums[i + 1]) continue;
            nums[right++] = nums[i];
        }

        int maxi = 0, count = 0, n = nums.size() - 1, left = 0;

        for(int i = 0; i < right; i++){
            while(left < right && (nums[left] - nums[i]) <= n){
                count++;
                left++;
            }

            maxi = max(maxi, count);
            count--;
        }

        return nums.size() - maxi;
    }
};