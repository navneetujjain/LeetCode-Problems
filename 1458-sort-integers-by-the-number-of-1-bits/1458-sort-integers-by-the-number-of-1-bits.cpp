class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto it : arr){
            int x = __builtin_popcount(it);
            pq.push({x, it});
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};