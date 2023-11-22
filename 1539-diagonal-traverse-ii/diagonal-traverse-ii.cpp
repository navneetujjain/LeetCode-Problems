#define pi pair<pair<int, int>, int>
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<nums[i].size(); j++)
            {
                pq.push({{i+j, j},nums[i][j]});
            }
        }
        
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};