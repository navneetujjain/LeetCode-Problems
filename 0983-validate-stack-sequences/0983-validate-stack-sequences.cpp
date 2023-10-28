class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;

        int st2 = 0;

        for(int i = 0; i < pushed.size(); i++){
            st.push(pushed[i]);

            while(!st.empty() && st2 < popped.size() && st.top() == popped[st2]){
                st2++;
                st.pop();
            }
        }

        if(st.empty() && st2 == popped.size()) return true;

        return false; 
    }
};