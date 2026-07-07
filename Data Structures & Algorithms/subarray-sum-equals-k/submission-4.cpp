class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        const int n = nums.size();
        int count = 0;
        unordered_map<int, int> M; // map -> (prefixSum, count)

        M[0] = 1;

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            int diff = sum - k;

            if (M.find(diff) != M.end())
                count += M[diff];

            if (M.find(sum) != M.end())
                M[sum]++;
            else
                M[sum] = 1;
        }

        return count;
    }
};
