class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;

        const int n1 = s1.size(), n2 = s2.size();
        vector<int> freq1(26, 0), freq2(26, 0);

        for (int i = 0; i < n1; i++)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        int i = 0, j = n1 - 1;

        while (j < n2)
        {
            if (freq1 == freq2)
                return true;

            freq2[s2[i] - 'a']--;

            i++;
            j++;

            if (j >= n2)
                break;

            freq2[s2[j] - 'a']++;
        }

        return false;
    }
};
