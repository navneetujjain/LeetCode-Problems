class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans = "";
        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/') continue;

            string dummy = "";

            while(i < path.size() && path[i] != '/'){
                dummy += path[i++];
            }

            if(dummy == ".") continue;

            else if(dummy == ".."){
                if(!st.empty()) st.pop();
            }

            else{
                st.push(dummy);
            }
        }

        while(!st.empty()){
            ans = '/' + st.top() + ans;
            st.pop();
        }
        if(ans.size()) return ans;

        return "/";
    }
};