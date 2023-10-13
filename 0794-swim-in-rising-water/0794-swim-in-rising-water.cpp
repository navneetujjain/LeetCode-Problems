class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0, 0}});

        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));

        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        vis[0][0] = 1;

        int maxi = 0;

        while(!pq.empty()){
            auto a = pq.top();
            pq.pop();

            int time = a.first;
            int x = a.second.first;
            int y = a.second.second;

            if(x == n - 1 && y == m - 1){
                return max(maxi, time);
            }

            maxi = max(maxi, time);

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] != 1){
                    vis[nx][ny] = 1;
                    pq.push({grid[nx][ny], {nx, ny}});
                }
            }
        }


        return maxi;
        


    }
};