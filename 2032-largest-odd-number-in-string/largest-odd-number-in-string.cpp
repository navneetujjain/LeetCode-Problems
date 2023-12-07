class Solution {
public:
    string largestOddNumber(string num) {
        int left = num.size() - 1;

        while(left >= 0){
            if(((int)(num[left])) % 2 != 0) break;

            else left--;
        }

        if(left >= 0) return num.substr(0, left + 1);


        return "";
    }
};