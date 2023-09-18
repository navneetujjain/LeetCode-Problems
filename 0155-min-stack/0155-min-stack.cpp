class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(st.empty()) return -1;
        vector<int> arr;
        int mini = INT_MAX;
        while(!st.empty()){
            arr.push_back(st.top());
            mini = min(mini, st.top());
            st.pop();
        }

        for(int i = arr.size() - 1; i >= 0; i--) st.push(arr[i]);

        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */