class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        string push = "Push", pop = "Pop";
        vector<string> ans;
        int index = 0;
        for(int i = 1; i <= n; i++){
            if(index == target.size()) break;
            else if(i == target[index]){
                ans.push_back(push);
                index++;
            }
            else{
                ans.push_back(push);
                ans.push_back(pop);
            }

        }

        return ans;
    }
};