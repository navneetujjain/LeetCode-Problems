class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ans1 = 0, ans2 = 0;

        for(auto it : arr1) ans1 ^= it;

        for(auto it : arr2) ans2 ^= it;

        return ans1 & ans2;
    }
};