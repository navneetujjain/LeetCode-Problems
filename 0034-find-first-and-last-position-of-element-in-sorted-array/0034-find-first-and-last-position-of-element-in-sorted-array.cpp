class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};

        auto x = lower_bound(nums.begin(), nums.end(), target);
        if (x != nums.end() && *x == target) {
            ans[0] = distance(nums.begin(), x);
        }

        auto y = upper_bound(nums.begin(), nums.end(), target);
        if (y != nums.begin() && *(y - 1) == target) {
            ans[1] = distance(nums.begin(), y - 1);
        }

        return ans;
    }
};