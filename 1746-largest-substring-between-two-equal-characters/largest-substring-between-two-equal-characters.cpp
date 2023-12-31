class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<int, int> mpp;

        int maxi = -1;

        for(int i = 0; i < s.size(); i++){
            if(mpp.find(s[i]) != mpp.end()){
                maxi = max(maxi, i - mpp[s[i]] - 1);
            }

            else mpp[s[i]] = i;
        }

        return maxi;
    }
};