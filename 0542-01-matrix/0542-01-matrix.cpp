class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        } 


        int dirx[] = {-1, 0, +1, 0};
        int diry[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto x = q.front();
            q.pop();

            int row = x.first.first;
            int col = x.first.second;
            int distance = x.second;

            for(int i = 0; i < 4; i++){
                int nrow = row + dirx[i];
                int ncol = col + diry[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 
                && ncol < m && mat[nrow][ncol] == 1 && vis[nrow][ncol] != 1){
                    vis[nrow][ncol] = 1;
                    ans[nrow][ncol] = distance + 1;
                    q.push({{nrow, ncol}, distance + 1});
                }
            }
        }

        return ans;

    }
};