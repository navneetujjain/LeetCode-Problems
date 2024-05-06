class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        if(numRows == 1) return {{1}};
        ans.push_back({1});
        ans.push_back({1, 1});

        for(int i = 2; i < numRows; i++){
            vector<int> temp;
            for(int j = 0; j < i; j++){
                if(j == 0) temp.push_back(1);
                else temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }

        return ans;
    }
};