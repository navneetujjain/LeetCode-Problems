class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        for(int i = 0;; i++){
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast) break;
        }

        fast = nums[0];

        for(int i = 0;; i++){
            if(fast == slow) break;
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};