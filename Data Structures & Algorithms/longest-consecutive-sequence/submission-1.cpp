class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();

        unordered_map<int, int> M; // map -> (num, freq)
        int longestCount = 1, currCount = 1;

        for (const int &num : nums)
        {
            M[num] = (M.find(num) != M.end()) ? M[num]++ : 1;
        }

        for (const int &num : nums)
        {
            if (M.find(num - 1) == M.end())
                continue;

            int currNum = num;

            while (M.find(currNum) != M.end())
            {
                currNum++;
                currCount++;
            }

            longestCount = max(currCount, longestCount);
            currCount = 1;
        }

        return longestCount;
    }
};
