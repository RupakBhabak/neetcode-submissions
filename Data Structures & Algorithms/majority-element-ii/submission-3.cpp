class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        const int n = nums.size();
        unordered_map<int, int> M; // map -> (num, freq). its size will be alws <= 3. O(1) space

        // Find potential candidates
        for (const int &num : nums)
        {
            if (M.find(num) != M.end())
                M[num]++;
            else
                M[num] = 1;

            if (M.size() > 2)
            {
                unordered_map<int, int> tempM;

                for (const auto &elem : M)
                {
                    if (elem.second > 1)
                        tempM[elem.first] = elem.second - 1;
                }

                M = tempM;
            }
        }

        // Reset the frequencies of the potential candidates
        for (auto &elem : M)
        {
            elem.second = 0;
        }

        // Count the acual frequency of each potential candidate
        for (const int &num : nums)
        {
            if (M.find(num) != M.end())
                M[num]++;
        }

        for (const auto &elem : M)
        {
            if (elem.second > n / 3)
                ans.push_back(elem.first);
        }

        return ans;
    }
};
