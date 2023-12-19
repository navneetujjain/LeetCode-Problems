class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> count;
        for (char c : s1) {
            count[c]++;
        }

        int left = 0, right = 0;
        int requiredChars = s1.size();

        while (right < s2.size()) {
            if (count[s2[right]] > 0) {
                requiredChars--;
            }
            count[s2[right]]--;
            right++;

            if (requiredChars == 0) {
                return true;
            }

            if (right - left == s1.size()) {
                if (count[s2[left]] >= 0) {
                    requiredChars++;
                }
                count[s2[left]]++;
                left++;
            }
        }

        return false;
    }
};