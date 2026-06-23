class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        unordered_map<int, int> M;         // map -> (item, freq)
        priority_queue<pair<int, int>> PQ; // pq -> (freq, item) (max heap)

        for (const int &num : nums)
        {
            (M.find(num) != M.end()) ? M[num]++ : M[num] = 0;
        }

        for (const auto &elem : M)
        {
            PQ.push(make_pair(elem.second, elem.first));
        }

        for (int i = 0; i < k; i++)
        {
            ans.push_back(PQ.top().second);
            PQ.pop();
        }

        return ans;
    }
};
