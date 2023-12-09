class Solution {
public:
    bool f(int day, vector<int> bloomDay, int m, int k){
        int tot_flowers = 0, bouquet = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                tot_flowers++;
                if(tot_flowers == k){
                    bouquet++;
                    tot_flowers = 0;
                }
            }
            else tot_flowers = 0;
        }

        if(bouquet >= m) return true;

        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long)m * k > bloomDay.size()) return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int u = *max_element(bloomDay.begin(), bloomDay.end());


        while(l < u){
            int mid = l + (u - l) / 2;

            if(f(mid, bloomDay, m, k)) u = mid;
            else l = mid + 1;
        }

        return l;
    }
};