class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 1)
            return 0;

        int totalProfit = 0;
        int i = 0, j = 0;
        bool hasBought = false;

        while (i < prices.size() && j < prices.size())
        {
            if (i == prices.size() - 1 || j == prices.size() - 1)
            {
                if (hasBought)
                    totalProfit += prices[j] - prices[i];
                break;
            }
            else
            {
                if (hasBought)
                {
                    if (prices[j + 1] < prices[j])
                    {
                        hasBought = false;
                        totalProfit += prices[j] - prices[i];
                        i = j + 1;
                    }
                    j++;
                }
                else
                {
                    if (prices[i + 1] > prices[i])
                        hasBought = true;
                    else
                        i++;
                    j++;
                }
            }
        }

        return totalProfit;
    }
};
