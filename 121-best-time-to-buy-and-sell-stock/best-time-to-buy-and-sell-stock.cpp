class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = INT_MAX;
        for(auto it : prices){
            if(it < mini) mini = it;
            else profit = max(profit, it - mini);
        }

        return profit;
    }
};