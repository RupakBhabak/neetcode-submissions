class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m; // map->(number, freq)

        for (const int &num : nums)
        {
            if (m.find(num) == m.end())
            {
                m[num] = 1;
            }
            else
            {
                return num;
            }
        }

        return 0;
    }
};
