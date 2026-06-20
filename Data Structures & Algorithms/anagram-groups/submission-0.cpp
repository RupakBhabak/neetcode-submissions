class Solution {
public:
    bool is_anagram(string &a, string &b)
    {
        vector<int> freqArr(26, 0);

        for (char ch : a)
        {
            freqArr[ch - 'a']++;
        }

        for (char ch : b)
        {
            freqArr[ch - 'a']--;
        }

        for (int freq : freqArr)
        {
            if (freq != 0)
                return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<pair<string, bool>> temp; // pair -> (str, is_done/is_added)
        vector<vector<string>> ans;

        for (string str : strs)
        {
            temp.push_back(make_pair(str, false));
        }

        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i].second == true)
                continue;

            vector<string> subList;
            subList.push_back(temp[i].first);
            temp[i].second = true;

            int j = i + 1;

            while (j < temp.size())
            {
                if (is_anagram(temp[i].first, temp[j].first))
                {
                    subList.push_back(temp[j].first);
                    temp[j].second = true;
                }
                j++;
            }

            ans.push_back(subList);
        }

        return ans;
    }
};
