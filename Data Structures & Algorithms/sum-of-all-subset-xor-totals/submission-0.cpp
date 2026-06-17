class Solution {
public:
    int subset_xor_sum_helper(int i, vector<int> &nums, int currXor)
    {
        if (i >= nums.size())
            return currXor;

        // include
        int leftAns = subset_xor_sum_helper(i + 1, nums, currXor ^ nums[i]);

        // doesn't include
        int rightAns = subset_xor_sum_helper(i + 1, nums, currXor);

        return leftAns + rightAns;
    }

    int subsetXORSum(vector<int> &nums)
    {
        return subset_xor_sum_helper(0, nums, 0);
    }
};