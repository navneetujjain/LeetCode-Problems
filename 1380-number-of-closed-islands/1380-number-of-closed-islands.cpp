class Solution {
public:
    int rule = 0;
    void bfs(int i, int j, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid){
        queue<pair<int, int>> q;
        q.push({i, j});
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        if(i == 0 || i == n - 1 || j == 0 || j == m - 1) rule = 0;

        while(!q.empty()){
            auto a = q.front();
            q.pop();
            int x = a.first;
            int y = a.second;

            vis[x][y] = 1;

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m 
                && vis[nx][ny] == 0 && grid[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    if(nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1) rule = 0;

                    q.push({nx, ny});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0 && vis[i][j] == 0){
                    rule = 1;
                    bfs(i, j, n, m, vis, grid);

                    if(rule) count++;
                }
            }
        }

        return count;
    }
};