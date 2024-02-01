class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>result;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/3;i++) {
            int a=nums[i*3+0];
            int b=nums[i*3+1];
            int c=nums[i*3+2];
            if(c-a<=k) {
                vector<int>temp;
                temp.push_back(a);
                temp.push_back(b);
                temp.push_back(c);
                result.push_back(temp);
            } else {
                result.clear();
                return result;
            }
        }
        return result;
    }
};