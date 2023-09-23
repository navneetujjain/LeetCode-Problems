class Solution {
public:
    void dfs(int start, vector<vector<int>> &adj, vector<int> &vis){
        vis[start] = 1;

        for(int i = 0; i < adj.size(); i++){
            if(vis[i] != 1 && adj[start][i] == 1){
                dfs(i, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int ans = 0;
        int n = arr.size();
        vector<int> vis(n + 1, 0);

        for(int i = 0; i < arr.size(); i++){
            if(vis[i] != 1){
                dfs(i, arr, vis);
                ans++;
            }
        }
        return ans;
    }
};