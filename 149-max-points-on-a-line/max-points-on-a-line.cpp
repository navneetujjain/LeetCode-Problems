class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        int ans = 2;

        if(n == 1) return 1;

        for(int i = 0; i < n; i++){
            unordered_map<double, int> mpp;
            for(int j = 0; j < n; j++){

                if(j == i) continue;
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];

                double slope = atan2((y2 - y1),(x2 - x1));

                mpp[slope]++;

                ans = max(ans, mpp[slope] + 1);
            }
        }

        return ans;
    }
};