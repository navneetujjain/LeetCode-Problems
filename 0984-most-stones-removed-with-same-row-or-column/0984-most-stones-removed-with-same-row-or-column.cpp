class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> adj[n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n + 1, 0);
        queue<int> q;
        int count = 0;

        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                q.push(i);
                vis[i] = 1;
                count++;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it : adj[node]){
                        if(!vis[it]){
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }

        return n - count;
    }
};