class Solution {
public:
    int countCollisions(string arr) {
        int n = arr.size();
        stack<char> st;
        st.push(arr[0]);
        int count = 0;
        for(int i = 1; i < arr.size(); i++){
            if(!st.empty() && st.top() == 'R' && arr[i] == 'L'){
                st.pop();
                count += 2;
                st.push('S');
            }
            else if(!st.empty() && st.top() == 'R' && arr[i] == 'S'){
                st.pop();
                count += 1;
                st.push('S');
            }
            else if(!st.empty() && st.top() == 'S' && arr[i] == 'L'){
                st.pop();
                count += 1;
                st.push('S');
            }
            else st.push(arr[i]);
        }

        while(!st.empty() && st.top() == 'R') st.pop();
        while(!st.empty()){
            if(st.top() == 'R') count++;
            st.pop();
        }

        return count;
    }
};