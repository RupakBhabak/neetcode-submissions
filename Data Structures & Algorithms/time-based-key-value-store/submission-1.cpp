class TimeMap
{
private:
    string binary_search(vector<pair<string, int>> &vec, int &timestamp)
    {
        const int n = vec.size();
        int nearest = -1;
        int l = 0, r = n - 1;

        while (l <= r)
        {
            int m = (r - l) / 2 + l;

            if (vec[m].second == timestamp)
                return vec[m].first;

            if (vec[m].second < timestamp)
                nearest = m;

            if (timestamp > vec[m].second)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        if (nearest != -1)
            return vec[nearest].first;
        else
            return "";
    }

public:
    unordered_map<string, vector<pair<string, int>>> M;

    TimeMap()
    {
        return;
    }

    void set(string key, string value, int timestamp)
    {
        if (M.find(key) == M.end())
            M[key] = vector<pair<string, int>>(0);

        M[key].push_back(make_pair(value, timestamp));
    }

    string get(string key, int timestamp)
    {
        return binary_search(M[key], timestamp);
    }
};