class Solution {
public:
    void merge(vector<int> &nums, int l, int m, int r)
    {
        int i = l, j = m + 1, k;
        vector<int> temp;

        while (i <= m && j <= r)
        {
            if (nums[i] <= nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= m)
        {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= r)
        {
            temp.push_back(nums[j]);
            j++;
        }

        k = 0;
        for (i = l; i <= m; i++)
        {
            nums[i] = temp[k];
            k++;
        }

        for (i = m + 1; i <= r; i++)
        {
            nums[i] = temp[k];
            k++;
        }
    }

    void merge_sort(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {
            int mid = l + (r - l) / 2;

            merge_sort(nums, l, mid);
            merge_sort(nums, mid + 1, r);

            merge(nums, l, mid, r);
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> result = nums;
        merge_sort(result, 0, result.size() - 1);
        return result;
    }
};