class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char, int> mpp;

        for(char it : s1) mpp[it]++;


        int left = 0, right = 0, req = s1.size();

        while(right < s2.size()){
            if(mpp[s2[right]] > 0){
                req--;
            }

            mpp[s2[right]]--;
            right++;

            if(req == 0) return true;

            if(right - left == s1.size()){
                if(mpp[s2[left]] >= 0){
                req++;
            }
                mpp[s2[left]]++;
                left++;
            }

        }

        return false;
    }
};