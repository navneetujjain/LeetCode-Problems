class Solution {
public:
    vector<int> findArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n, 0), ans(n, 0);

        //ans[0] = arr[0];
        ans[0] = arr[0];
        int prev = arr[0];

        for(int i = 1; i < n; i++){
            prev = prev ^ arr[i];
            ans[i] = prev;
            prev = prev ^ arr[i - 1];
        }

        return ans;

    }
};