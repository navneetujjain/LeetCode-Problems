class Solution {
public:
    vector<string> ans;
    bool isValid(string a, string b){

        int edits = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                if(edits >= 2) return false;
                else edits++;
            }
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
        for(int i = 0; i < queries.size(); i++){
            for(int j = 0; j < dict.size(); j++){
                if(isValid(queries[i], dict[j])){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};