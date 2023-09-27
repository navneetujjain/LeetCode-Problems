class Solution {
public:
    string decodeAtIndex(string str, int k) {
        long long length = 0;

        for(auto it : str){
            if(isdigit(it)){
                length *= it - '0';
            }
            else length++;
        }

        for(int i = str.size() - 1; i >= 0; i--){
            if(isdigit(str[i])){
                length = length / (str[i] - '0');
                k = k  % length;
            }
            else{
                if(k == 0 || length == k) return string("") + str[i];

                length--;
            }
        }

        return "";
    }
};