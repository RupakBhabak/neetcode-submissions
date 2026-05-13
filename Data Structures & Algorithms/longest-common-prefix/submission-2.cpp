class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string pref = "";
        int maxStrSize = 0;

        for (string elem : strs)
        {
            maxStrSize = max(maxStrSize, (int)elem.size());
        }

        if (maxStrSize == 0)
        {
            return pref;
        }

        char currCh;
        int totElems = strs.size();
        int count = 0;
        int i = 0;

        while (i <= maxStrSize - 1)
        {
            if (count == 0)
            {
                currCh = strs[count][i];
            }

            if (strs[count][i] == currCh)
            {
                if (count == totElems - 1)
                {
                    i++;
                    count = 0;
                    pref += currCh;
                }
                else
                {
                    count++;
                }
            }
            else
            {
                return pref;
            }
        }

        return pref;
    }
};