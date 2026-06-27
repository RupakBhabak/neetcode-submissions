class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        const int n = nums.size();
        int product = 1;
        vector<int> ans(n);
        vector<int> prefixArr(n), suffixArr(n);

        for (int i = 0; i < n; i++)
        {
            prefixArr[i] = product;
            product *= nums[i];
        }

        product = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            suffixArr[i] = product;
            product *= nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            ans[i] = prefixArr[i] * suffixArr[i];
        }

        return ans;
    }
};
