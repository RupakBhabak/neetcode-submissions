class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        const int n = nums.size();

        if (k > n)
            k = k % n;
        if (k == 0)
            return;

        vector<int> ans;

        int i = n - 1;
        int count = 1;

        while (count < k)
        {
            i--;
            count++;
        }

        int j = i, l = 0;

        while (i < n)
        {
            ans.push_back(nums[i]);
            i++;
        }

        while (l != j)
        {
            ans.push_back(nums[l]);
            l++;
        }

        for (int i = 0; i < n; i++)
        {
            nums[i] = ans[i];
        }
    }
};
