# Design Twitter

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the `10` most recent tweets in the user's news feed.

Implement the `Twitter` class:

- Twitter() Initializes your twitter object.
- void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
- List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
- void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
- void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.

 

 **Example 1:** 

```
Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.

```

 

 **Constraints:** 

- 1 <= userId, followerId, followeeId <= 500
- 0 <= tweetId <= 104
- All the tweets have unique IDs.
- At most 3 * 104 calls will be made to postTweet, getNewsFeed, follow, and unfollow.
- A user cannot follow himself.

## Solution

**Language:** C++  
**Runtime:** 23 ms (beats 13.34%)  
**Memory:** 55.8 MB (beats 72.80%)  
**Submitted:** 2026-10-14T09:51:36.636Z  

```cpp

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

```

---

[View on LeetCode](https://leetcode.com/problems/design-twitter/)