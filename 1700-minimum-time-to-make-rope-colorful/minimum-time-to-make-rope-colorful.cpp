class Solution {
public:
    int f(int start, int end, const vector<int> &arr){
        int summer = 0, mini = 0;
        for(int i = start; i < end && i < arr.size(); i++){
            summer += arr[i];
            mini = max(mini, arr[i]);
        }

        return summer - mini;
    }
    int minCost(string colors, vector<int>& arr) {
        int remove = 0;

        int n = colors.size();
        for(int i = 0; i < n - 1; i++){
            int j = i + 1;
            if(colors[i] == colors[i + 1]){
                while(j < n && colors[j] == colors[i]) j++;

                remove += f(i, j, arr);
            }
            i = j - 1;
        }

        return remove;
    }
};