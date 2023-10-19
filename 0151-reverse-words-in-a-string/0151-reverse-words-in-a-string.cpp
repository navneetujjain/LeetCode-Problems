class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);

        vector<string> arr;
        string temp = "";
        while(ss >> temp){
            arr.push_back(temp);
        }

        string ans = "";
        for(int i = arr.size() - 1; i >= 0; i--){
            ans += arr[i];
            ans += ' ';
        }

        ans.pop_back(); //Last Element Hatane ke liye

        return ans;
    }
};