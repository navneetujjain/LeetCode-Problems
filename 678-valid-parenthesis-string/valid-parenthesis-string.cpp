class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> star;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == '*'){
                star.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty()){
                    if(star.empty()) return false;
                    else star.pop();
                }
                else st.pop();
            }
        }
        while(!st.empty() && !star.empty()){
            if(star.top() > st.top()){
                star.pop();
                st.pop();
            }
            else break;
        }
        return st.empty();
    }
};