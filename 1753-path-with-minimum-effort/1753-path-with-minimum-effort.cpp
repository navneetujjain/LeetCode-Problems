class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int m = heights[0].size(), n = heights.size();

        if(n - 1 == 0 && m - 1 == 0) return 0;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        vector<vector<int>> effort(n + 1, vector<int>(m + 1, 1e9));

        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int oldeff = x.first;
            int oldx = x.second.first;
            int oldy = x.second.second;

            if(oldx == n - 1 && oldy == m - 1) return oldeff;

            for(int i = 0; i < 4; i++){
                int nx = oldx + dx[i];
                int ny = oldy + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int newEffort = max(oldeff, abs(heights[oldx][oldy] - heights[nx][ny]));
                    if (newEffort < effort[nx][ny]) {
                        effort[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }

        return 0;
    }
};