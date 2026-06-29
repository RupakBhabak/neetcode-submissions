class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();

        unordered_set<int> S;
        int longestCount = 1;

        for (const int &num : nums)
        {
            S.insert(num);
        }

        for (int num : nums)
        {
            if (S.count(num - 1))
                continue;

            int currCount = 1;
            num++;

            while (S.count(num))
            {
                currCount++;
                num++;
            }

            longestCount = max(currCount, longestCount);
        }

        return longestCount;
    }
};
