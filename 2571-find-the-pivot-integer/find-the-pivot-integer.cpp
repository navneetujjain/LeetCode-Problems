class Solution {
public:
    int pivotInteger(int n) {
        int sum=n*(n+1)/2;      //sum from 1 to n;
        for(int i=n/2;i<=n;i++)
        {   
            int sum_to_i=i*(i+1)/2;
            if(sum_to_i==(sum-sum_to_i+i))return i; //there is +i because we want sum from i to n 
                                                    //not from i-1 to n;
        }
        return -1;
    }
};