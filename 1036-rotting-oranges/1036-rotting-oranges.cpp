class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int vis[n][m];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
                else vis[i][j] = 0;
            }
        }

        int time = 0;
        int rowCheck[] = {-1, 0, +1, 0};
        int colCheck[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int qtime = q.front().second;
            time = max(time, qtime);
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + rowCheck[i];
                int ncol = col + colCheck[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, qtime + 1});
                }
            }
        }

         for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 2) return -1;
            }
        }

        return time;


    }
};