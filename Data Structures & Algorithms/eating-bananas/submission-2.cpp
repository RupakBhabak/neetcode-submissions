class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        const int n = piles.size();
        int k, cur = 0, l = 1, r;
        
        sort(piles.begin(), piles.end());

        r = piles[n - 1];
        k = piles[n - 1];

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
