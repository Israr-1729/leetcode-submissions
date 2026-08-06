class AuthenticationManager {
public:
    int sessionTime = 0;

    // tokenId -> expiryTime
    unordered_map<string, long long> exp;

    AuthenticationManager(int timeToLive) { sessionTime = timeToLive; }

    void generate(string tokenId, int currentTime) {
        exp[tokenId] = currentTime + sessionTime;
    }

    void renew(string tokenId, int currentTime) {
        for (auto it = exp.begin(); it != exp.end();) {
            if (it->second <= currentTime)
                it = exp.erase(it);
            else
                ++it;
        }

        if (exp.contains(tokenId))
            exp[tokenId] = currentTime + sessionTime;
    }

    int countUnexpiredTokens(int currentTime) {

        for (auto it = exp.begin(); it != exp.end();) {
            if (it->second <= currentTime)
                it = exp.erase(it);
            else
                ++it;
        }
        return exp.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */