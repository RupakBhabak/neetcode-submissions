class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return vector<vector<int>>(0);

        const int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end()); // O(nlog(n))

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;

            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;

                int l = j + 1, r = n - 1;
                long long subTarget = (long long)target - nums[i] - nums[j];

                while (l < r)
                {
                    if (l > j + 1 && nums[l - 1] == nums[l])
                    {
                        l++;
                        continue;
                    }

                    if (r < n - 1 && nums[r + 1] == nums[r])
                    {
                        r--;
                        continue;
                    }

                    long long sum = (long long)nums[l] + nums[r];

                    if (sum == subTarget)
                    {
                        vector<int> currAns = {nums[i], nums[j], nums[l], nums[r]};
                        ans.push_back(currAns);
                    }

                    if (sum > subTarget)
                        r--;
                    else
                        l++;
                }
            }
        }

        return ans;
    }
};
