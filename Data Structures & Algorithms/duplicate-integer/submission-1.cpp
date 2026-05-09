class Solution {
public:
    bool hasDuplicate(vector<int> &nums)
{
    unordered_map<int, int> M;

    for (int val : nums)
    {
        if (M.count(val) == 0)
            M[val] = 1;
        else
            M[val]++;
    }

    for (auto const &pair : M)
    {
        if (pair.second > 1)
            return true;
    }

    return false;
}
};