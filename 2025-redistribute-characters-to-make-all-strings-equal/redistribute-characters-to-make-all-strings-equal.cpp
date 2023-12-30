class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> mpp;

        for(int i = 0; i < words.size(); i++){
            for(auto it : words[i]) mpp[it]++;
        }

        int n = words.size();
        for(auto it : mpp){
            if(it.second % n != 0) return false;
        }

        return true;
    }
};