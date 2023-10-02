class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;

        int n = grid.size();
        int m = grid[0].size();

        if(m == 1 && grid[0][0] == 0) return 1;

        int reach_x = n - 1;
        int reach_y = m - 1;

        queue<pair<int, pair<int, int>>> q;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        q.push({1, {0, 0}});

        int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

        while(!q.empty()){
            auto x = q.front();
            q.pop();

            int distance = x.first;
            int dirx = x.second.first;
            int diry = x.second.second;

            for(int i = 0; i < 8; i++){
                int nx = dirx + dx[i];
                int ny = diry + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m 
                && grid[nx][ny] == 0 && 1 + distance < dist[nx][ny]){
                    dist[nx][ny] = 1 + distance;
                    if(nx == n - 1 && ny == m - 1) return 1 + distance;
                    q.push({1 + distance, {nx, ny}});
                }
            }
        }

        return -1;
    }
};