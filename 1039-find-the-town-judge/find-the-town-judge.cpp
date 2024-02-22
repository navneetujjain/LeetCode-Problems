class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<unordered_set<int>> graph(n+1, unordered_set<int>());
        for (auto& edge : trust) {
            int a = edge[0], b = edge[1];
            graph[a].insert(b); // a trust b
        }
        for (int cand = 1; cand <= n; ++cand) {
            if (graph[cand].size() == 0) {
                bool isGood = true;
                for (int other = 1; other <= n; ++other) {
                    if (other == cand) continue;
                    if (graph[other].count(cand) == 0) {
                        isGood = false;
                        break;
                    }
                }
                if (isGood) return cand;
            }
        }
        return -1;
    }
};