class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> stt(wordList.begin(), wordList.end());

        stt.erase(beginWord);
        while(!q.empty()){
            auto x = q.front();
            string word = x.first;
            int time = x.second;
            q.pop();
            if(word == endWord) return time;
            for(int i = 0; i < word.size(); i++){
                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(stt.find(word) != stt.end()){
                        q.push({word, time + 1});
                        stt.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};