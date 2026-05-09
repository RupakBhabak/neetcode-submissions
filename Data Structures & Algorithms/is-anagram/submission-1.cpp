class Solution {
public:
    void map_string(string &s, unordered_map<char, int> &M)
    {
        for (char ch : s)
        {
            if (M.find(ch) == 0)
            {
                M[ch] = 1;
            }
            else
            {
                M[ch]++;
            }
        }
    }

    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> M1, M2;

        map_string(s, M1);
        map_string(t, M2);

        for (char ch : s)
        {
            if (M2.find(ch) == 0)
            {
                return false;
            }
            else
            {
                if (M2[ch] != M1[ch])
                {
                    return false;
                }
            }
        }

        for (char ch : t)
        {
            if (M1.find(ch) == 0)
            {
                return false;
            }
            else
            {
                if (M1[ch] != M2[ch])
                {
                    return false;
                }
            }
        }

        return true;
    }
};
