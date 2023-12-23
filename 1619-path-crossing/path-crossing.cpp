class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> stt;
        stt.insert({0, 0});
        int x = 0, y = 0;
        for(char it : path){
            if(it == 'N') y += 1;
            else if(it == 'S') y -= 1;
            else if(it == 'E') x += 1;
            else x -= 1;

            //if(stt.find({x, y}) != stt.end()) return true;
            stt.insert({x, y});
        }

        return stt.size() - 1 != path.size();
    }
};