class Solution {
public:
    int minOperations(string s) {
        int count0 = 0, count1 = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0' && i % 2 == 0){
                count1++;
            }
            else if(s[i] == '0' && i % 2 != 0){
                count0++;
            }
            else if(s[i] == '1' && i % 2 == 0){
                count0++;
            }
            else if(s[i] == '1' && i % 2 != 0){
                count1++;
            }
        }

        return min(count0, count1);
    }
};