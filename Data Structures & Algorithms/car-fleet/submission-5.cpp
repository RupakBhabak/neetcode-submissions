class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.size() == 1)
            return 1;
        
        const int n = position.size();
        vector<pair<int, int>> cars; // cars[i] -> (pos, speed)
        int fleet = 1;

        for (int i = 0; i < n; i++)
        {
            cars.push_back(make_pair(position[i], speed[i]));
        }

        sort(cars.begin(), cars.end());

        float prevTime = (target - cars[n-1].first) / (float)cars[n-1].second;

        for (int i = n - 2; i >= 0; i--)
        {
            float currTime = (target - cars[i].first) / (float)cars[i].second;

            if (currTime > prevTime)
            {
                fleet++;
                prevTime = currTime;
            }
        }

        return fleet;
    }
};
