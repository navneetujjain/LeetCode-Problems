class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int z = INT_MIN;
        int n = nums.size();

        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            if(nums[i] < z) return true;

            else{
                while(!st.empty() && nums[i] > st.top()){
                    z = st.top();
                    st.pop();
                }
            }
            st.push(nums[i]);
        }

        return false;
        
    }
};