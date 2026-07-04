class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 1)
            return 0;

        int totalProfit = 0;
        int i = 0, j = 0;

        while (i < prices.size() - 1 && j < prices.size() - 1)
        {
            if (prices[j + 1] < prices[j])
            {
                // sell
                totalProfit += prices[j] - prices[i];
                i = j;
            }

            if (prices[i] > prices[i + 1])
                i++;

            j++;
        }

        totalProfit += prices[j] - prices[i]; // for final sell (if any)

        return totalProfit;
    }
};
