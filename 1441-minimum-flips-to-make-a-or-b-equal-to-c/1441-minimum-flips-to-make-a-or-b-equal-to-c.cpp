class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;

        while(a || b || c){
            int bit_a = a & 1;
            int bit_b = b & 1;
            int bit_c = c & 1;

            a = a >> 1;
            b = b >> 1;
            c = c >> 1;

            if(bit_c == 0){
                if(bit_a == 1 && bit_b == 1) ans += 2;
                else if(bit_a || bit_b) ans += 1;
            }
            else if(bit_c == 1){
                if(bit_a == 0 && bit_b == 0) ans += 1;
            }
        }

        return ans;
    }
};