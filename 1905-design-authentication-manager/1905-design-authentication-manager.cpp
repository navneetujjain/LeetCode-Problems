class AuthenticationManager {
public:
    unordered_map<string, int> mpp;
    int ttl = 0;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        if(mpp.find(tokenId) == mpp.end()) mpp[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mpp.find(tokenId) != mpp.end() && mpp[tokenId] > currentTime) mpp[tokenId] = currentTime + ttl;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;

        for(auto it : mpp){
            if(it.second > currentTime) count++;
        }

        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */