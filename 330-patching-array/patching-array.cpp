class Solution {
public:
    int minPatches(vector<int>& coins, int n) {
        long long int additioncount = 0, sum = 0, index = 0;

        while(sum < n){
            if(index < coins.size() && coins[index] <= sum + 1){
                sum += coins[index];
                index++;
            }
            else{
                sum += sum + 1;
                additioncount++;
            }
        }

        return additioncount;
    }
};