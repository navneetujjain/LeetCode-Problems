class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};

        unordered_map<char, int> mpp;

        for(char it : p) mpp[it]++;

        int left = 0, right = 0, req = p.size();
        vector<int> ans;

        while (right < s.size()) {
            if (mpp.find(s[right]) != mpp.end()) {
                if (mpp[s[right]] > 0) {
                    req--;
                }
                mpp[s[right]]--;
            }

            right++;

            if (right - left == p.size()) {
                if (req == 0) {
                    ans.push_back(left);
                }

                if (mpp.find(s[left]) != mpp.end()) {
                    if (mpp[s[left]] >= 0) {
                        req++;
                    }
                    mpp[s[left]]++;
                }

                left++;
            }
        }

        return ans;   
    }
};