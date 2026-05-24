class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)
            return 0;

        int i = 0, j = 1;
        int maxProfit = 0;

        while (i < prices.size() && j < prices.size()) {
            int currProfit = prices[j] - prices[i];

            if (currProfit < 0) {
                i++;
            } else {
                maxProfit = max(currProfit, maxProfit);
                j++;
            }
        }

        return maxProfit;
    }
};
