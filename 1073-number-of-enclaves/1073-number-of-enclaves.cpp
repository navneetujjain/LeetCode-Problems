class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i == 0 || j == 0 || i == n  - 1 || j == m - 1) && grid[i][j] == 1){
                    q.push({i, j});
                    grid[i][j] = 2;
                    vis[i][j] = 1;
                }
            }
        }

        int drow[] = {-1, 0, +1, 0}; 
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int row = x.first;
            int col = x.second;

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) ans++;
            }
        }

        return ans;
    }
};