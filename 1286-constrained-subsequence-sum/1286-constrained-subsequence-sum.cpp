class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;

        pq.push({nums[0], 0}); //index 0 ke elements push kar diye

        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++){
            while(i - pq.top().second > k) pq.pop();

            int take = max(0,  pq.top().first) + nums[i];
            ans = max(ans, take);
            pq.push({take, i});
        }

        return ans;
        
    }
};