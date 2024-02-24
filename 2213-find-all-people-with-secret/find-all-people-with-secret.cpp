class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    void reset(int x) {
        parent[x] = x;
        size[x]=1;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int fp) {
        sort(meetings.begin(), meetings.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int meetno = meetings.size();
        DisjointSet ds(n);
        ds.unionBySize(0, fp);
        int ind = 0;
        while(ind < meetno){
            int time = meetings[ind][2];
            int start = ind;
            while(ind<meetno&&time==meetings[ind][2])
            {
                ds.unionBySize(meetings[ind][0], meetings[ind][1]);
                ind++;
            }
            while(start<ind){
                if(ds.findUPar(meetings[start][0])!=ds.findUPar(0)){
                    ds.reset(meetings[start][0]);
                    ds.reset(meetings[start][1]);
                }
                start++;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(ds.findUPar(i)==ds.findUPar(0)) ans.push_back(i);
        }
        return ans;
    }
};