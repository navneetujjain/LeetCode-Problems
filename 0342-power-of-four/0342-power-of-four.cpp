class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0) return false;
        if(n % 4 != 0 && n != 1) return false;

        while(n != 0){
            n = n / 4;
            if(n % 4 != 0 && n != 1) return false;
        }

        return true;
    }
};