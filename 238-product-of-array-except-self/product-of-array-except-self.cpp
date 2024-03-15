class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> result;
      int product = 1;
      int zerocount = 0;
      int dummyproduct = 1;
      for(int i = 0; i < nums.size(); i++){
        product = product * nums[i];
        if(nums[i] == 0){
          zerocount++;
        }
        else dummyproduct = dummyproduct * nums[i];
      }
      if(zerocount == 0){
        for(int i = 0; i < nums.size(); i++){
          int x = product / nums[i];
          result.push_back(x);
        }
      }
      else if(zerocount == 1){
        for(int i = 0; i < nums.size(); i++){
          if(nums[i] == 0) result.push_back(dummyproduct);
          else result.push_back(0);
        }
      }
      else{
        for(int i = 0; i < nums.size(); i++) result.push_back(0);
      }
      return result;
    }
};