class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dT) {
        vector<vector<int>> graph(n, vector<int>(n, 1e9));

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            graph[u][v] = wt;
            graph[v][u] = wt; 
        }

        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    graph[i][j] = min(graph[i][via] + graph[via][j], graph[i][j]);
                    if(i == j) graph[i][j] = 0;
                }
            }
        }

        int city = INT_MIN, mini = INT_MAX;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(i != j && graph[i][j] <= dT) count++;
            }

            if(count <= mini){
                mini = count;
                city = max(city, i);
            }
        }

        return city;
    }
};