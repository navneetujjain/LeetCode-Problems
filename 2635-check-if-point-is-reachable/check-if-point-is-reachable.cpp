class Solution {
public:
    bool isReachable(int targetX, int targetY) {

        while(targetX % 2 == 0) targetX = targetX / 2;
        while(targetY % 2 == 0) targetY = targetY / 2;

        return __gcd(targetX, targetY) == 1;
        
    }
};