
class Solution {
public:
    bool isPalindrome(string s) {
    int lambai = s.size();
    int l = 0, h = lambai - 1;
    
    while(l < h){
        if(isalnum(s[l]) && isalnum(s[h])) {
            if(tolower(s[l]) != tolower(s[h]))
                return false;
            l++;
            h--;
        }
        if(!isalnum(s[l]))
            l++;
        if(!isalnum(s[h]))
            h--;        
    }
    return true;
        
    }
};