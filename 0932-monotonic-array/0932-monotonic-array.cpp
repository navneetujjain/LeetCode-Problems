class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() <= 2) return true;

        int n = nums.size();
        bool inc = true;
        bool dec = true;

        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i + 1]) inc = false;
        }

        for(int i = 0; i < n - 1; i++){
            if(nums[i] < nums[i + 1]) dec = false;
        }

        return inc || dec;
    }
};