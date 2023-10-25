class Solution {
public:

    int dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis){
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;

        if(grid[i][j] == 0 || vis[i][j] == 1) return 0;

        vis[i][j] = 1;

        int left = dfs(i, j - 1, n, m, grid, vis);
        int right = dfs(i, j + 1, n, m, grid, vis);
        int up = dfs(i - 1, j, n, m, grid, vis);
        int down = dfs(i + 1, j, n, m, grid, vis);

        return 1 + up + down + left + right;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));

        int maxcount = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int count = dfs(i, j, n, m, grid, vis);
                    maxcount = max(count, maxcount);
                }
            }
        }

        return maxcount;
    }
};