class Solution {
public:
    int kthGrammar(int n, int k) {
        bool check = true;

        n = pow(2, n - 1);

        while(n != 1){
            n = n / 2;

            if(k > n){
                check = !check;
                k = k - n;
            }
        }

        return check == true ? 0 : 1;
    }
};