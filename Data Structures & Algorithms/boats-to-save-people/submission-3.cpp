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
        int left = 0, right = n - 1;
        int count = 0;

        stable_sort(people.begin(), people.end());

        while (left <= right)
        {
            if (left == right)
            {
                if (people[left] <= limit)
                    count++;

                break;
            }

            int currWeight = people[left] + people[right];

            if (currWeight <= limit)
            {
                count++;
                left++;
                right--;
            }

            if (currWeight > limit)
            {
                if (people[right] <= limit)
                    count++;
                right--;
            }
        }

        return count;
    }
};
