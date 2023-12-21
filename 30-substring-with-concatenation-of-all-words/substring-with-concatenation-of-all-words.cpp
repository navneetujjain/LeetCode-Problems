class Solution {
public:
    int f(unordered_map<string, int> mpp, string s, int len){
        for(int i = 0; i < s.size(); i += len){
            string word = s.substr(i, len);
            if(mpp.find(word) != mpp.end()){
                if(--mpp[word] == -1) return 0;
            }
            else return 0;
        }

        return 1;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int wordsize = words[0].size(), window = words.size() * wordsize;
        //Assume karna hai ki size sabka same hai
        unordered_map<string, int> mpp;
        for(auto it : words){
            mpp[it]++;
        }

        int index = 0;

        while(index + window <= s.size()){
            if (f(mpp, s.substr(index, window), wordsize)) ans.push_back(index);
            index++;
        }

        return ans;
    }
};