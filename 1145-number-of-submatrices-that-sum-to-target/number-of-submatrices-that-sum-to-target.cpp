class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                unordered_map<int, int> mpp;
                mpp[0] = 1;
                int sum = 0;

                for(int k = 0; k < m; k++){
                    sum += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    count += mpp[sum - target];
                    mpp[sum]++;
                }
            }
        }

        return count;
    }
};