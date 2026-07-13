class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        const int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end()); // O(nlog(n))

        // nums[i] + nums[j] + nums[k] = 0
        // => -nums[i] = (nums[j] + nums[k])
        // Then its a 2Sum like problem
        // where pairs are nums[j] & nums[k] and target is -nums[i]

        int i = 0;

        while (i < n)
        {
            int j = i + 1, k = n - 1;
            int target = -nums[i];

            while (j < k)
            {
                int sum = nums[j] + nums[k];

                if (sum == target)
                {
                    vector<int> currAns = {nums[i], nums[j], nums[k]};
                    ans.push_back(currAns);
                }

                if (sum > target)
                {
                    int currNum = nums[k];
                    while (j < k && nums[k] == currNum)
                        k--;
                }
                else
                {
                    int currNum = nums[j];
                    while (j < k && nums[j] == currNum)
                        j++;
                }
            }

            int currNum = nums[i];
            while (i < n && nums[i] == currNum)
                i++;
        }

        return ans;
    }
};
