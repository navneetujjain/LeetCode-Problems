class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        map<char, int> mpp;

        for(auto it : s) mpp[it]++;

        for(auto it : mpp) pq.push({it.second, it.first});

        string ans = "";
        while(!pq.empty()){
            int freq = pq.top().first;
            char x = pq.top().second;
            pq.pop();

            for(int i = 0; i < freq; i++) ans += x;
        }

        return ans;
    }
};