class Solution {
public:
    bool isArithmetic( vector<int> vec) {
    sort(vec.begin(),vec.end());
    if (vec.size() < 2) {
        return true;
    }

    int diff = vec[1] - vec[0];

    for (int i = 1; i < vec.size() - 1; i++) {
        if (vec[i + 1] - vec[i] != diff) {
            return false; 
        }
    }

    return true;
}
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=l.size();
        vector<bool>result(n);

        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=l[i];j<=r[i];j++){
                temp.push_back(nums[j]);
            }
            result[i]=isArithmetic(temp);
        }
        return result;
    }
};