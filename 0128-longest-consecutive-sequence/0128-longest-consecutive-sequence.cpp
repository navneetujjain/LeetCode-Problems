class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        priority_queue<int> pq;

        for(auto it : nums) pq.push(it);

        int maxlen = 1, len = 1;

        while(!pq.empty()){
            int front = pq.top();
            pq.pop();
            if(pq.top() == front - 1) len++;

            else if(pq.top() == front) continue;

            else len = 1;

            maxlen = max(len, maxlen);
        }

        return maxlen;
    }
};