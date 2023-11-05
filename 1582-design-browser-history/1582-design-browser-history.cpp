class BrowserHistory {
public:
    stack<string> st1;
    stack<string> st2;
    BrowserHistory(string homepage) {
        visit(homepage);
    }
    
    void visit(string url) {
        st1.push(url);
        st2 = stack<string>();
    }
    
    string back(int steps) {
        while(steps > 0 && st1.size() > 1){
            st2.push(st1.top());
            st1.pop();
            steps--;
        }

        return st1.top();
    }
    
    string forward(int steps) {
        while(steps > 0 && st2.size() > 0){
            st1.push(st2.top());
            st2.pop();
            steps--;
        }
        return st1.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */