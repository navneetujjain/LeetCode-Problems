class Solution {
public:
    void dfs(string email, map<string, int>& vis, map<string, vector<string>> &mpp, vector<string> &ds){
        vis[email] = 1;
        ds.push_back(email);
        for(auto it : mpp[email]){
            if(vis.find(it) == vis.end()){
                dfs(it, vis, mpp, ds);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,vector<string>> mpp;
        int n = accounts.size();
        for(int i = 0;i < n; i++)
        {
            int k = accounts[i].size();
            for(int j = 1;j<k;j++)
            {
                for(int l = j + 1;l < k; l++)
                {
                    mpp[accounts[i][j]].push_back(accounts[i][l]);
                    mpp[accounts[i][l]].push_back(accounts[i][j]);
                }
            }
        }

        map<string, int> vis;
        vector<vector<string>> ans;

        for(int i = 0; i < n; i++){
            vector<string> ds;
            ds.push_back(accounts[i][0]);
            if(vis.find(accounts[i][1]) == vis.end()){
                dfs(accounts[i][1], vis, mpp, ds);
                if(ds.size() > 1) ans.push_back(ds);
            }
        }

        for(int i = 0; i < ans.size(); i++){
            sort(ans[i].begin() + 1, ans[i].end());
        }

        return ans;
        
    }
};