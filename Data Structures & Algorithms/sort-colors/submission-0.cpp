class Solution {
public:
    void sortColors(vector<int> &nums)
    {
        unordered_map<int, int> M; // map -> (colorCode, freq)

        M[0] = 0;
        M[1] = 0;
        M[2] = 0;

        for (const int &num : nums)
        {
            M[num]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (M[0])
            {
                nums[i] = 0;
                M[0]--;
            }
            else if (M[1])
            {
                nums[i] = 1;
                M[1]--;
            }
            else if (M[2])
            {
                nums[i] = 2;
                M[2]--;
            }
        }
    }
};