class Twitter {
public:
    int time; // to count the time
    unordered_map<int, deque<pair<int, int>>> tweetMap; // a pair of (time, tweetID)
    unordered_map<int, unordered_set<int>> followMap; // unordered_set for quicker search and erase
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time, tweetId});
        if(tweetMap[userId].size() > 10) tweetMap[userId].pop_front();
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        followMap[userId].insert(userId); // also would show their own tweets
        priority_queue<vector<int>> maxHeap;
        // 1. Grab the single newest tweet from everyone the user follows
        for (auto f : followMap[userId]) {
            if (!tweetMap.count(f) || tweetMap[f].empty()) continue;
            int idx = tweetMap[f].size() - 1; // Index of their newest tweet
            auto& p = tweetMap[f][idx];
            maxHeap.push({p.first, p.second, f, idx - 1}); // Push {time, tweetId, userId, nextIndexToCheck}
        }

        // 2. Pop the most recent tweets, and push the next one from that user
        while (!maxHeap.empty() && res.size() < 10) {
            auto t = maxHeap.top();
            maxHeap.pop();
            res.push_back(t[1]); // Add tweetId to result
            int idx = t[3]; // The index of the next newest tweet for this specific user
            if (idx >= 0) { // check if the followee still has tweets
                auto& p = tweetMap[t[2]][idx];
                maxHeap.push({p.first, p.second, t[2], idx - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followMap[followerId].count(followeeId)) followMap[followerId].erase(followeeId);
    }
};







