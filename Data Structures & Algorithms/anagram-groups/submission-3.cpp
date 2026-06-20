class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> M;

        for (const string &str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());

            M[key].push_back(str);
        }

        for (const auto &item : M)
        {
            ans.push_back(item.second);
        }

        return ans;
    }
};
