class Solution {
public:
    void bfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<int>> &vis){
        vis[i][j] = 1;

        queue<pair<int, int>> q;

        q.push({i, j});

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            int x = a.first;
            int y = a.second;

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 
                && ny < m && grid[nx][ny] == '1' && vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));

        int maxcount = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    bfs(i, j, n, m, grid, vis);
                    maxcount++;
                }
            }
        }

        return maxcount;
    }
};