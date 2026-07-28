class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        const int n = arr.size();
        int l = 0, r = n - k;
        vector<int> ans;

        while (l < r)
        {
            int m = l + (r - l) / 2;

            if (x - arr[m] > arr[m + k] - x)
                l = m + 1;
            else
                r = m;
        }

        for (int i = l; i < l + k; i++)
        {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};