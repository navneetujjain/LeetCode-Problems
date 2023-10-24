class Solution {
public:
    void dfs(vector<int> &vis, int i, int n, vector<int> adj[]){
        vis[i] = 1;

        for(auto it : adj[i]){
            if(vis[it] != 1){
                dfs(vis, it, n, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> vis(n + 1, 0);


        vector<int> adj[n + 1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j]){
                    adj[i + 1].push_back(j + 1);
                }
            }
        }

        int count = 0;


        for(int i = 1; i <= n; i++){
            if(vis[i] == 0){
                count++;
                dfs(vis, i, n, adj);
            }
        }

        return count;
    }
};