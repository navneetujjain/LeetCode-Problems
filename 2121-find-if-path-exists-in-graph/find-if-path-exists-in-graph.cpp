class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> discovered(n);
        stack<int> st;
        st.push(source);
        while (st.size() > 0) {
            int u = st.top();
            if (u == destination) return true;
            for (int v : adj[u]) {
                if (!discovered[v]) {    
                    st.push(v);
                    discovered[v] = true;
                    break;
                }
            }
            if (u == st.top()) {
                st.pop();
            }
        }
        return false;
    }
};