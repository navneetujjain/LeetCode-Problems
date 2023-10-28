class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++){
            if(s[i] != ']') st.push(s[i]);
            else{
                string temp = "";

                while(st.top() != '['){
                    temp = st.top() + temp;
                    st.pop();
                }

                st.pop();
                string num = "";

                while(!st.empty() && isdigit(st.top())){
                    num = st.top() + num;
                    st.pop();
                }

                int total = stoi(num);

                while(total--){
                    for(int x = 0; x < temp.size(); x++) st.push(temp[x]);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};