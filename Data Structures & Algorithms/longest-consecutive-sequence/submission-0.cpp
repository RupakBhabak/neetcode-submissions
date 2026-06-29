class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();

        priority_queue<int, vector<int>, greater<int>> PQ; // min-heap
        int longestCount = 1, currCount = 1;

        for (const int &num : nums)
        {
            PQ.push(num);
        }

        int prevNum = PQ.top();
        PQ.pop();

        while (!PQ.empty())
        {
            int currNum = PQ.top();
            PQ.pop();

            if (currNum == prevNum)
                continue;

            if (currNum - prevNum == 1)
            {
                currCount++;
            }
            else
            {
                longestCount = max(longestCount, currCount);
                currCount = 1;
            }

            prevNum = currNum;
        }

        longestCount = max(longestCount, currCount);

        return longestCount;
    }
};
