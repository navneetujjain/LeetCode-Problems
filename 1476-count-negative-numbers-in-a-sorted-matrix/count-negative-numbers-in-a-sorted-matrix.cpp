class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int i = n - 1, j = 0, ans = 0;

        while(i >= 0 && j >= 0 && i < n && j < m){
            if(grid[i][j] < 0){
                ans += (m - j);
                i = i - 1;
            }

            else j = j + 1;
        }

        return ans;
        
    }
};