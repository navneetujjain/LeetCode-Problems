class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int n = matrix[0].size();

        vector<int> height(n + 1);

        int maxArea = 0;

        for(int x = 0; x < matrix.size(); x++){
            for(int j = 0; j < n; j++){
                if(matrix[x][j] == '1') height[j] = height[j] + 1;
                else height[j] = 0;
            }

        stack<int> st;
        st.push(-1);

        for(int i = 0; i < n + 1; i++){
            while(st.top() != -1 && height[st.top()] > height[i]){
                int x = height[st.top()];
                st.pop();
                int width = i - st.top() - 1;
                maxArea = max(maxArea, width * x);
            }
            st.push(i);
        }
    }

        return maxArea;
        
    }
};