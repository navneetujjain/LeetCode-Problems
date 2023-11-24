class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int maxi = 0;
        sort(piles.begin(), piles.end());

        int left = 0, right = piles.size() - 1;

        while(left < right){
            right--;
            maxi += piles[right--];
            left++;
        }

        return maxi;
    }
};