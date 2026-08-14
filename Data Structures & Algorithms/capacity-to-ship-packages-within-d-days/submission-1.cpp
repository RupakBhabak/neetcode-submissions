class Solution {
public:
    int get_max(vector<int>& weights)
    {
        int m = weights[0];

        for (int i = 1; i < weights.size(); i++)
        {
            m = max(m, weights[i]);
        }

        return m;
    }

    int get_sum_weights(vector<int>& weights)
    {
        int sum = 0;

        for (const int &weight : weights)
        {
            sum += weight;
        }

        return sum;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        const int n = weights.size();
        int l = get_max(weights), r = get_sum_weights(weights), cap; // cap -> capacity

        cap = l;

        while (l <= r)
        {
            int curC = (r - l) / 2 + l; // current capacity
            int curD = 1; // current day
            int curW = 0; // current weight

            for (int i = 0; i < n; i++)
            {
                int net = curW + weights[i]; // net weight

                if (net > curC)
                {
                    curD++;
                    curW = weights[i];
                }
                else if (net == curC)
                {
                    curD++;
                    curW = 0;
                }
                else
                {
                    curW = net;
                }

                if (i == n - 1 && curW == 0)
                    curD--;
            }

            if (curD <= days)
            {
                cap = curC;
                r = curC - 1;
            }
            else
            {
                l = curC + 1;
            }
        }

        return cap;
    }
};