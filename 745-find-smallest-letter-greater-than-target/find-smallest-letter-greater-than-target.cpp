class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;

        if (letters[r] <= target) {
            return letters[0];
        }

        while(l <= r){
            int mid = l + (r - l)/2;

            if(letters[mid] > target) r = mid - 1;
            else l = mid + 1;
        }

        return letters[l];
    }
};