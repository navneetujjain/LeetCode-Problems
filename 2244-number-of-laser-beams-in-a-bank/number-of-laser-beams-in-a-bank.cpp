class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevcount = 0;
        int total = 0;
        for(auto it : bank){
            int newcount = 0;

            for(auto x : it){
                if(x == '1') newcount++;
            }

            int newsum = prevcount * newcount;

            if(newcount > 0) prevcount = newcount;

            total += newsum;
        }

        return total;
    }
};