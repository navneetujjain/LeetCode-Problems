class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = nums.size() - 1;
        int i = j;
        while(i >= 0 && j >= 0){
            while(j >= 0 && nums[j] == 0){
                j--;
            }
            if(nums[i] == 0){
                int index = i;
                while(index < j && index != j){
                    swap(nums[index], nums[index + 1]);
                    index++;
                }
            }
            i--;
        }
    }
};