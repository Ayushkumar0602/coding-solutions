
class Twitter {
private:
    int timer = 0;

    
    unordered_map<int, vector<pair<int, int>>> tweets;

    
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timer, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        
        priority_queue<tuple<int, int, int, int>> pq;

       
        following[userId].insert(userId);

       
        for (int followee : following[userId]) {
            if (!tweets[followee].empty()) {
                int idx = tweets[followee].size() - 1;

                auto [time, tweetId] = tweets[followee][idx];

                pq.push({time, tweetId, followee, idx});
            }
        }

        vector<int> feed;

        while (!pq.empty() && feed.size() < 10) {
            auto [time, tweetId, author, idx] = pq.top();
            pq.pop();

            feed.push_back(tweetId);

            
            if (idx > 0) {
                auto [prevTime, prevTweetId] =
                    tweets[author][idx - 1];

                pq.push({
                    prevTime,
                    prevTweetId,
                    author,
                    idx - 1
                });
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
