class Solution {
public:
    int minimumRounds(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(auto it : nums) mpp[it]++;

        int count = 0;

        for(auto it : mpp){
            if(it.second == 1) return -1;

            else if(it.second % 3 == 1){
                count += (it.second / 3) + 1;
            }

            else if(it.second % 3 == 2){
                count += (it.second / 3) + 1;
            }

            else count += (it.second / 3);
        }

        return count;
    }
};