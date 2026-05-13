class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string pref = "";
        int i = 0;

        while (true)
        {
            char ch = strs[0][i];

            if (strs[0] == "")
                return pref;

            for (string elem : strs)
            {
                if (elem[i] != ch)
                    return pref;
            }

            pref += ch;

            for (string elem : strs)
            {
                if (i == elem.size() - 1)
                    return pref;
            }

            i++;
        }

        return pref;
    }
};