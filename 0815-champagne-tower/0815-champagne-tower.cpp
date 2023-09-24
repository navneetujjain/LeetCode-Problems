class Solution {
public:
    double solve ( int volume , int row , int col, vector<vector<double>>&dp){
        if ( row<0 || col<0 ) return static_cast<double>(0);
        if ( row==0 && col ==0 ) return volume; 
        if (dp[row][col]!=-1) return dp[row][col]; 
        double left = (solve( volume , row-1 , col-1,dp)-1)/2; 
        double right =( solve ( volume , row-1 , col,dp)-1)/2; 
        if ( left <0 )left = 0.00; 
        if ( right <0 ) right = 0.00; 
        return dp[row][col]=left+right<0?0.00000:left+right; 
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(101,vector<double>(101,-1));  
        return min(1.00,solve(poured, query_row, query_glass,dp));
    }
};