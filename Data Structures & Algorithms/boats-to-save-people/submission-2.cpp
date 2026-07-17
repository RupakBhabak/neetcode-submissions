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

        stable_sort(people.begin(), people.end());

        while (i <= j)
        {
            if (i == j)
            {
                if (people[i] <= limit)
                    count++;

                break;
            }

            int currWeight = people[i] + people[j];

            if (currWeight <= limit)
            {
                count++;
                i++;
                j--;
            }

            if (currWeight > limit)
            {
                if (people[j] <= limit)
                    count++;
                j--;
            }
        }

        return count;
    }
};
