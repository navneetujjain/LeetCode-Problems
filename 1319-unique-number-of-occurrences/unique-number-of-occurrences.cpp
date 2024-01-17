class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp, freq;

        for(auto it : arr) mpp[it]++;

        for(auto it : mpp){
            if(freq.find(it.second) != freq.end()) return false;
            else freq[it.second]++;
        }

        return true;
    }
};