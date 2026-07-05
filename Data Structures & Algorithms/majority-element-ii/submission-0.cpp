class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        unordered_map<int, int> M; // map -> (num, freq)
        const int n = nums.size();

        for (const int &num : nums)
        {
            if (M.find(num) != M.end())
                M[num]++;
            else
                M[num] = 1;
        }

        for (const auto &elem : M)
        {
            if (elem.second > n / 3)
                ans.push_back(elem.first);
        }

        return ans;
    }
};
