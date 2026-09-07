class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        unordered_map<double, vector<vector<int>>> m;               // map -> (dist, points(xi, yi))
        priority_queue<double, vector<double>, greater<double>> pq; // minHeap for distance
        vector<vector<int>> ans;

        for (const vector<int> &point : points)
        {
            double dist = pow(0 - point[0], 2) + pow(0 - point[1], 2);
            
            if (m.find(dist) == m.end())
                pq.push(dist);
            
            m[dist].push_back({point[0], point[1]});
        }

        int i = 0;

        while (i < k)
        {
            for (const vector<int> &point : m[pq.top()])
            {
                ans.push_back(point);
                i++;

                if (i >= k)
                    break;
            }

            pq.pop();
        }

        return ans;
    }
};
