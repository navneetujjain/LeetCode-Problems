class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<char>> ans(n, vector<char>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O'){
                    board[i][j] = 'p';
                    q.push({i, j});
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
                && vis[nrow][ncol] != 1 && board[nrow][ncol] == 'O'){
                    q.push({nrow, ncol});
                    board[nrow][ncol] = 'p';
                    vis[nrow][ncol] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'p') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};