class Solution {
public:
    int get_max(vector<int>& piles)
    {
        int m = piles[0];
        
        for (int i = 1; i < piles.size(); i++)
        {
            m = max(m, piles[i]);
        }

        return m;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        const int n = piles.size();
        int k, cur = 0, l = 1, r, maxItem;

        maxItem = get_max(piles);

        r = maxItem;
        k = maxItem;

        while (l < r)
        {
            int mid = (r - l) / 2 + l;
            cur = 0;

            for (int i = 0; i < n; i++)
            {
                cur += (piles[i] + mid - 1) / mid; // ceiling div
            }

            if (cur <= h)
            {
                k = mid;
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return k;
    }
};
