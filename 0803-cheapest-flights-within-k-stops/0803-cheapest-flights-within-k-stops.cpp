class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];

        vector<int> cost(n, 1e9);

        cost[src] = 0;

            for(auto it : flights){
                adj[it[0]].push_back({it[1], it[2]});
            }

        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}});

        while(!q.empty()){
            auto x = q.front();
            int oldk = x.first;
            int node = x.second.first;
            int money = x.second.second;
            q.pop();

            if(oldk > k) continue;

            for(auto it : adj[node]){
                int newnode = it.first;
                int newcost = it.second;

                if(newcost + money < cost[newnode] && oldk <= k){
                    cost[newnode] = newcost + money;
                    q.push({oldk + 1, {newnode, newcost + money}});
                }
            }
        }

        if(cost[dst] == 1e9) return -1;

        return cost[dst];


    }
};