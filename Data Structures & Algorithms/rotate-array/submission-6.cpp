class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();

        if (k == 0)
            return;

        const int n = nums.size();
        int i = 0, j = n - 1;

        // reverse the array

        while (i < j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        // reverse the first k elements again

        i = 0, j = k - 1;

        while (i < j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        // reverse the remaining (n-k) elements again

        i = k, j = n - 1;

        while (i < j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};
