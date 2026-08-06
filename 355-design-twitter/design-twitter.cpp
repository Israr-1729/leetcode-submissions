class Twitter {
public:
    int timer = 0;

    unordered_map<int, vector<pair<int,int>>> tweets;

    unordered_map<int, unordered_set<int>> following;

    Twitter() {

    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        struct Node {
            int time;
            int tweetId;
            int userId;
            int index;

            bool operator<(const Node &other) const {
                return time < other.time;
            }
        };

        priority_queue<Node> pq;

        if (!tweets[userId].empty()) {
            int idx = tweets[userId].size() - 1;
            pq.push({
                tweets[userId][idx].first,
                tweets[userId][idx].second,
                userId,
                idx
            });
        }

        for (int followee : following[userId]) {
            if (!tweets[followee].empty()) {
                int idx = tweets[followee].size() - 1;
                pq.push({
                    tweets[followee][idx].first,
                    tweets[followee][idx].second,
                    followee,
                    idx
                });
            }
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {

            Node cur = pq.top();
            pq.pop();

            ans.push_back(cur.tweetId);

            if (cur.index > 0) {
                int newIndex = cur.index - 1;

                pq.push({
                    tweets[cur.userId][newIndex].first,
                    tweets[cur.userId][newIndex].second,
                    cur.userId,
                    newIndex
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};