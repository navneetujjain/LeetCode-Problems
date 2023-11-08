class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(sy - fy);
        int y = abs(sx - fx);

        if(x == 0 && y == 0 && t == 1) return 0;

        return max(x, y) <= t ? 1 : 0;
    }
};