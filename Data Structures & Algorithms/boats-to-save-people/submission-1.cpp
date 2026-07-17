class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        if (people.size() == 1)
        {
            if (people[0] <= limit)
                return 1;
            else
                return 0;
        }

        const int n = people.size();
        int i = 0, j = n - 1;
        int count = 0;
        vector<pair<int, bool>> markedPeople;

        for (int i = 0; i < n; i++)
        {
            markedPeople.push_back(make_pair(people[i], false));
        }

        stable_sort(markedPeople.begin(), markedPeople.end());

        while (i < j)
        {
            int currWeight = markedPeople[i].first + markedPeople[j].first;

            if (currWeight <= limit)
            {
                count++;
                markedPeople[i].second = true;
                markedPeople[j].second = true;
                i++;
                j--;
            }

            if (currWeight > limit)
                j--;
        }

        for (int i = 0; i < n; i++)
        {
            if (!markedPeople[i].second && markedPeople[i].first <= limit)
                count++;
        }

        return count;
    }
};
