class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans(0);
        unordered_map<int, int> M; // map -> (item, freq)
        vector<vector<int>> freqArr(nums.size() + 1, vector<int>(0));

        for (const int &num : nums)
        {
            (M.find(num) != M.end()) ? M[num]++ : M[num] = 1;
        }

        for (const auto &elem : M)
        {
            freqArr[elem.second].push_back(elem.first);
        }

        for (int i = freqArr.size() - 1; i >= 0; i--)
        {
            if (freqArr[i].size() != 0)
            {
                for (int j = 0; j < freqArr[i].size() && k > 0; j++)
                {
                    ans.push_back(freqArr[i][j]);
                    k--;
                }
            }

            if (k <= 0)
                break;
        }

        return ans;
    }
};
