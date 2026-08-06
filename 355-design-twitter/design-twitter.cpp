class Twitter {
public:

    vector<vector<int>> allTweets; 
    unordered_map<int, unordered_set<int>> following;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        allTweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        for(int i = allTweets.size() - 1; i>=0; i--)
        {
            if(following[userId].contains(allTweets[i][0]) || allTweets[i][0] == userId)
            {
            result.push_back(allTweets[i][1]);
            }

            if(result.size() == 10)
            break;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */