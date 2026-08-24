class TimeMap
{
public:
    unordered_map<string, unordered_map<int, string>> M;

    TimeMap()
    {
        return;
    }

    void set(string key, string value, int timestamp)
    {
        M[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        if (M.find(key) == M.end())
        {
            return "";
        }
        else
        {
            int nearest = timestamp;

            while (nearest >= 0 && M[key].find(nearest) == M[key].end())
            {
                nearest--;
            }

            if (nearest >= 0)
            {
                return M[key][nearest];
            }
            else
            {
                return "";
            }
        }
    }
};