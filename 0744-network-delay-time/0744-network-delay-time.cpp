class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];

        for(auto it : times) adj[it[0]].push_back({it[1], it[2]});

        queue<pair<int, int>> q;

        vector<int> dist(n + 1, 1e9);

        dist[k] = 0;

        q.push({k, 0});

        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int node = x.first;
            int oldcost = x.second;

            for(auto it : adj[node]){
                int newnode = it.first;
                int newcost = it.second;

                if(oldcost + newcost < dist[newnode]){
                    dist[newnode] = newcost + oldcost;
                    q.push({newnode, newcost + oldcost});
                }
            }
        }

        int ans = -1;
        for(int i = 1; i <= n; i++){
            ans = max(ans, dist[i]);
        }

        if(ans == 1e9) return -1;

        return ans;




        
    }
};