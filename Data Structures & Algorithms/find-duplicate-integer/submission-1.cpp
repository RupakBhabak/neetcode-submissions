class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res;
        int slow = 0, fast = 0;

        while (true)
        {
            slow = nums[slow];

            fast = nums[fast];
            fast = nums[fast];

            if (slow == fast)
                break;
        }

        int slow2 = 0;

        while (true)
        {
            slow = nums[slow];
            slow2 = nums[slow2];

            if (slow == slow2)
            {
                res = slow2;
                break;
            }
        }

        return res;
    }
};
