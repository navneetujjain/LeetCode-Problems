#define INF 1e6 + 1
class Solution {
public:

    int BinarySearch(int x, vector<vector<int>>& a)
    {
        int start = 0, end = a.size() - 1;
        int res = INF;
        while(start <= end)
        {
            int mid = (start + end) / 2;

            if(a[mid][0] < x) start = mid + 1;
            else
            {
                res = a[mid][0];
                end = mid - 1;
            }
        }
        return res;
    }

    vector<int> findRightInterval(vector<vector<int>>& in) 
    {
        vector<int> res(in.size(), -1);
        //Index Mapping
        unordered_map<int,int> mpp;
        for(int i = 0; i < in.size(); i++)
            mpp[in[i][0]] = i;
        

        auto cmp = [](vector<int>&a, vector<int>&b){ return a[0] < b[0]; };
        sort(in.begin(), in.end(), cmp);

        for(auto& x : in)
        {
            int start = BinarySearch(x[1], in);
            res[mpp[x[0]]] = (start == INF) ? -1 : mpp[start];
        }

        return res;
    }
};