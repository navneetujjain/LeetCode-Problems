class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n + 1];
        vector<int> indegree(n + 1, 0);
        vector<int> maxTime(n + 1, 0);

        for(auto it : relations){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;

        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0){
                q.push(i);
                maxTime[i] = time[i - 1];
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                indegree[it]--;
                maxTime[it] = max(maxTime[node] + time[it - 1], maxTime[it]);

                if(indegree[it] == 0) q.push(it);
            }
        }

        int minTime = 0;

        for(int i = 1; i <= n; i++){
            minTime = max(minTime, maxTime[i]);
        }

        return minTime;

    }
};