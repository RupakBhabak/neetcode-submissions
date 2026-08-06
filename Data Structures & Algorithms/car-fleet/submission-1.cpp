class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.size() == 1)
            return 1;
        
        const int n = position.size();
        vector<pair<int, int>> cars; // cars[i] -> (pos, speed)
        stack<pair<int, int>> s; // (pos, speed)

        for (int i = 0; i < n; i++)
        {
            cars.push_back(make_pair(position[i], speed[i]));
        }

        sort(cars.begin(), cars.end());

        for (int i = n - 1; i >= 0; i--)
        {
            if (s.empty())
            {
                s.push(cars[i]);
                continue;
            }

            float t1 = ((float)target - s.top().first) / s.top().second;

            s.push(cars[i]);

            float t2 = ((float)target - s.top().first) / s.top().second;

            if (t2 <= t1)
                s.pop();
        }

        return s.size();
    }
};
