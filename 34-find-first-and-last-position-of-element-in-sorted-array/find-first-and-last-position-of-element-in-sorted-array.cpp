class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        //if(nums.size() < 2) return {-1, -1};
        //if(nums.size() == 1) return {0, 0};

        int n = nums.size();

        bool flag = false;

        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] < target) left = mid + 1;

            else if(nums[mid] > target) right = mid - 1;

            else if(nums[mid] == target){
                flag = true;
                left = mid;
                right = mid;
                break;
            }
        }

        if(flag == true){
            while(left >= 0 && nums[left] == target) left--;
            while(right < n && nums[right] == target) right++;
        }

        if(flag == true){
            ans.push_back(left + 1);
            ans.push_back(right - 1);
        }

        if(flag == false){
            ans.push_back(-1);
            ans.push_back(-1);
        }


        return ans;
    }
};