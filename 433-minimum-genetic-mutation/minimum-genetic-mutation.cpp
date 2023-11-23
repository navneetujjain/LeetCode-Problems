class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        string mutes = "ATGC";

        unordered_set<string> stt(bank.begin(), bank.end());

        while(!q.empty()){
            auto x = q.front();
            q.pop();
            string m = x.first;
            int count = x.second;

            if(m == endGene) return count;

            for(int i = 0; i < m.size(); i++){
                char revert = m[i];

                for(auto it : mutes){
                    m[i] = it;

                    if(stt.find(m) != stt.end()){
                        q.push({m, count + 1});
                        stt.erase(m);
                    }
                }

                m[i] = revert;
            }
        }

        return -1;
    }
};