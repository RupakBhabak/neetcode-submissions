class Solution
{
public:
    int count_of_most_freq(unordered_map<char, int> &M)
    {
        int count = 0;

        // max 26 letters
        // so max TC O(26) = O(1)

        for (const auto &elem : M)
        {
            count = max(elem.second, count);
        }

        return count;
    }

    int characterReplacement(string s, int k)
    {
        const int n = s.size();
        int l = 0, r = 0;
        int longest = 0, currLen = 1;
        unordered_map<char, int> M; // to track the freq of elements of current window (max size 26)

        // main formula for a valid window
        // len(window) - count(most frq. elem of that window) <= k

        while (l < n && r < n)
        {
            if (M.find(s[r]) == M.end())
                M[s[r]] = 1;
            else
                M[s[r]]++;

            if (currLen - count_of_most_freq(M) > k) // not <= k
            {
                while (currLen - count_of_most_freq(M) > k)
                {
                    M[s[l]]--;
                    l++;
                    currLen--;
                }
            }

            longest = max(currLen, longest);

            r++;
            currLen++;
        }

        return longest;
    }
};
