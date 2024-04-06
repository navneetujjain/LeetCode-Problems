class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp="",ans="";
        int open=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')temp+=s[i],open++;
            else if(s[i]==')' && open>0)temp+=s[i],open--;
            else if(s[i]!='(' && s[i]!=')')temp+=s[i];
        }
        for(int i=temp.size()-1;i>=0;i--){
            if(temp[i]=='(' && open>0)open--;
            else ans+=temp[i];
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};