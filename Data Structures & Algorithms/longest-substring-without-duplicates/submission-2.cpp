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
        int i = 0;
        unordered_set<char> St; // to track duplicates

        while (i < n)
        {
            if (St.find(s[i]) == St.end())
            {
                St.insert(s[i]);
                currLen++;
            }
            else
            {
                longest = max(currLen, longest);
                St.clear();
                currLen = 0;

                char currCh = s[i];
                i--;
                while (s[i] != currCh)
                    i--;
            }

            if (i == n - 1)
                longest = max(currLen, longest);

            i++;
        }

        return longest;
    }
};
