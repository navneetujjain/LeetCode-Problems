class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++){
          while(!st.empty() && arr[i] <= arr[st.top()]){
            int index = st.top();
            st.pop();
            right[index] = i;
          }
          st.push(i);
        }
        stack<int> pt;
        for(int i = n - 1; i >= 0; i--){
          while(!pt.empty() && arr[i] < arr[pt.top()]){
            int index = pt.top();
            pt.pop();
            left[index] = i;
          }
          pt.push(i);
        }
        long long res = 0;
        for(int i = 0; i < n; i++){
          int leftlen = i - left[i];
          int rightlen = right[i] - i;
          res = (res + ((long)arr[i] * leftlen * rightlen) % mod) % mod;
        }
        return int(res);
    }
};