class Solution
{
public:
};

class Twitter
{
private:
    unordered_map<int, vector<pair<int, int>>> tweetDB; // map -> (userID, List[(count, tweetID)])
    unordered_map<int, unordered_set<int>> followDB;    // map -> (followerID, Set(followeeID))
    int count;

public:
    Twitter()
    {
        count = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        tweetDB[userId].push_back({count, tweetId});

        if (tweetDB.size() > 10)
            tweetDB[userId].erase(tweetDB[userId].begin());

        count--; // more -ve means more recent
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        followDB[userId].insert(userId);

        for (const int &followeeId : followDB[userId])
        {
            if (tweetDB.find(followeeId) != tweetDB.end())
            {
                const vector<pair<int, int>> tweets = tweetDB[followeeId];
                int indx = tweets.size() - 1;
                minHeap.push({tweets[indx].first, tweets[indx].second, followeeId, indx});
            }
        }

        while (!minHeap.empty() && res.size() < 10)
        {
            vector<int> curr = minHeap.top();

            minHeap.pop();
            res.push_back(curr[1]);

            int indx = curr[3];

            if (indx > 0)
            {
                const pair<int, int> &tweet = tweetDB[curr[2]][indx - 1];
                minHeap.push({tweet.first, tweet.second, curr[2], indx - 1});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId)
    {
        followDB[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (followDB.find(followerId) != followDB.end())
            followDB[followerId].erase(followeeId);
    }
};