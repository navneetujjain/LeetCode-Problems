class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;

        for(int i = 0; i < 32; i++){
            if(left == right && left % 2 != 0) ans += (1 << i);

            left = left >> 1;
            right = right >> 1;
        }

        return ans;
    }
};