class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid, int color, int n, int m){
        if(i < 0 || j < 0 || i == n || j == m) return 0;

        if(grid[i][j] == 0 || grid[i][j] == color) return 0;
        
        int count = 1; // Zero nahi kyunki jis box me ho wo bhi to colored hai

        grid[i][j] = color;

        count += dfs(i + 1, j, grid, color, n, m) + dfs(i - 1, j, grid, color, n, m) 
                + dfs(i, j - 1, grid, color, n, m) + dfs(i, j + 1, grid, color, n, m);

        return count;

    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int color = 2;

        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int count = dfs(i, j, grid, color, n, m);
                    mpp[color++] = count;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    set<int> stt;

                    if(i - 1 >= 0 && grid[i - 1][j] != 0) stt.insert(grid[i - 1][j]);
                    if(i + 1 < n && grid[i + 1][j] != 0) stt.insert(grid[i + 1][j]);
                    if(j - 1 >= 0 && grid[i][j - 1] != 0) stt.insert(grid[i][j - 1]);
                    if(j + 1 < m && grid[i][j + 1] != 0) stt.insert(grid[i][j + 1]);

                    int sum = 1;

                    for(auto it : stt){
                        sum += mpp[it];
                    }

                    ans = max(ans, sum);
                }
            }
        }

        if(ans == 0) return n * m;

        return ans;
    }
};