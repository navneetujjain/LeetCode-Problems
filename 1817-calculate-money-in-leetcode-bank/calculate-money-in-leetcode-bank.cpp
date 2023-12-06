class Solution {
public:
    int totalMoney(int n) {
        int start = 1, sum = 0;

        for(int i = 0; i < n / 7; i++){
            int pseudosum = 7 * ((2 * start) + 6);

            sum += pseudosum/2;
            start++;
        }

        int x = n % 7;

        while(x--){
            sum += start++;
        }

        return sum;
    }
};