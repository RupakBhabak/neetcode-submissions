class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        const int n = nums.size();

        if (n == 0)
            return 0;

        int minLen = n + 1;
        int currSum = 0;
        int i = 0;

        for (int j = 0; j < n; j++)
        {
            currSum += nums[j];

            while (currSum >= target)
            {
                int currLen = j - i + 1;
                minLen = min(minLen, currLen);

                currSum -= nums[i];
                i++;
            }
        }

        // If minLen wasn't updated, no valid subarray exists
        return (minLen == n + 1) ? 0 : minLen;
    }
};
