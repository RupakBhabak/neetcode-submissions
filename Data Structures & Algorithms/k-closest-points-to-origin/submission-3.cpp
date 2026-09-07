class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // minHeap for {distance, xi, yi}
        vector<vector<int>> ans;

        for (const vector<int> &point : points)
        {
            double dist = pow(0 - point[0], 2) + pow(0 - point[1], 2);
            vector<int> elem = {(int)dist, point[0], point[1]};
            pq.push(elem);
        }

        for (int i = 0; i < k; i++)
        {
            vector<int> top = pq.top();
            ans.push_back({top[1], top[2]});
            pq.pop();
        }

        return ans;
    }
};