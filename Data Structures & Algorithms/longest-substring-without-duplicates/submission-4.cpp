class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0 || s.size() == 1)
            return s.size();

        const int n = s.size();
        int longest = 0;
        int currLen = 0;
        int i = 0, j = 0;
        unordered_set<char> St; // to track duplicates

        while (i < n && j < n)
        {
            if (St.find(s[j]) == St.end())
            {
                St.insert(s[j]);
                currLen++;
            }
            else
            {
                longest = max(currLen, longest);

                while (s[i] != s[j])
                {
                    St.erase(s[i]);
                    i++;
                }
                i++;

                currLen = j - i + 1;
            }

            if (j == n - 1)
                longest = max(currLen, longest);

            j++;
        }

        return longest;
    }
};
