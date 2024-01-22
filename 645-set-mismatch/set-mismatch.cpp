class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        bool seen[len + 1];
        vector<int> res(2);
        for (int i = 1; i <= len; i++) seen[i] = false;
        for (int i: nums) seen[i] = (!seen[i] || bool(1 + (res[0] = i)));
        for (int i = 1; i <= len; i++) if (!seen[i]) return res[1] = i, res;
        return res;
        
    }
};