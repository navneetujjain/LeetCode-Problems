class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n == 1) return nums[0];

        int i = k, j = k, ans = INT_MIN;

        int mini = nums[k];

        while(i > 0 || j < n - 1){
            if(j == n - 1) i--;
            else if(i == 0) j++;

            else if(nums[j + 1] > nums[i - 1]) j++;

            else i--;

            mini = min(mini, min(nums[i], nums[j]));

            ans = max(ans, mini * (j - i + 1));
        }

        return ans;
    }
};