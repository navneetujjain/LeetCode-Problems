class Solution {
public:
    int reverse(int x) {
        long long int a = x;
        int neg = 0;
        if(a < 0){
            neg = 1;
            a = a * -1;
        }

        long long int val = 0;
        while(a != 0){
            val += a % 10;
            a = a / 10;
            val = val * 10;
        }

        val = val/10;

        if(neg){
            val = val * -1;
            if(val < INT_MIN) return 0;
            else return val;
        }

        if(val > INT_MAX) return 0;

        return val;
    }
};