class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int xdist = 0, ydist = 0;

        int ans = 0;

        for(int i = 1; i < points.size(); i++){
            xdist = (abs(points[i- 1][0] - points[i][0]));
            ydist = (abs(points[i- 1][1] - points[i][1]));

            ans += max(xdist, ydist);
        }

        return ans;
    }
};