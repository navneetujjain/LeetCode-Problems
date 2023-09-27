class Solution {
public:
    bool dfs(int i, vector<int> &color, int prev, vector<vector<int>>& graph){
        color[i] = prev;

        for(auto it : graph[i]){
            if(color[it] == -1){
                if(dfs(it, color, !prev, graph) == false) return false;
            }
            else if(color[it] == prev) return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(dfs(i, color, 0, graph) == false) return false;
            }
        }

        return true;
    }
};