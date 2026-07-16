class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        const int n = heights.size();
        int maxWater = 0;
        int i = 0, j = n - 1;

        while (i < j)
        {
            int currWater = min(heights[i], heights[j]) * (j - i);
            maxWater = max(currWater, maxWater);

            if (heights[i] < heights[j])
                i++;
            else
                j--;
        }

        return maxWater;
    }
};
