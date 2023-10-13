class Solution {
public:
    int f(vector<int> &cost, int index, vector<int> &dp){
        if(index == cost.size() - 1) return cost[index];

        if(index >= cost.size()) return 0;
        if(dp[index] != -1) return dp[index];

        return dp[index] = cost[index] + min(f(cost, index + 1, dp), f(cost, index + 2, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp1(cost.size() + 1, -1);
        vector<int> dp2(cost.size() + 1, -1);
        return min(f(cost, 0, dp1), f(cost, 1, dp2));
    }
};