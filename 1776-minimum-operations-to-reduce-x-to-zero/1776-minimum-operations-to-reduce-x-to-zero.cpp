class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0, n = nums.size();
        for(int i = 0; i < n; i++) target += nums[i];

        target = target - x;

        if(target == 0) return n;

        int len = 0, sum = 0, left = 0;

        for(int right = 0; right < n; right++){
            sum += nums[right];

            while(left <= right && sum > target){
                sum -= nums[left];
                left++;
            }

            if(sum == target){
                len = max(len, right - left + 1);
            }
        }

        if(len) return n - len;

        return -1;
    }
};