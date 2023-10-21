class Solution {
public:
    int minBitFlips(int start, int goal) {
        int minbits = start ^ goal;

        int ans = 0;

        while(minbits != 0){
            ans += (minbits & 1);

            minbits = minbits >> 1;
        }

        return ans;
    }
};