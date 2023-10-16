class Solution {
public:
    int isPos(int ind, vector<int> &piles, int h){
        long long int tot = 0;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] % ind != 0){
                tot += (piles[i]/ind) + 1;
            }
            else tot += (piles[i] / ind);
        }

        return tot <= h ? 1 : 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = INT_MAX - 2, ans = INT_MAX;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(isPos(mid, piles, h)){
                high = mid - 1;
                ans = min(ans, mid);
            }
            else low = mid + 1;
        }

        return ans;
    }
};