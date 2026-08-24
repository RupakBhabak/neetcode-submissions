class Solution {
public:
    bool search(vector<int>& nums, int target) {
        const int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r)
        {
            int mid = (r - l) / 2 + l;

            if (nums[mid] == target)
                return true;

            if (nums[l] < nums[mid]) // If it is in left sorted part
            {
                if (nums[l] <= target && target <= nums[mid]) 
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else if (nums[l] > nums[mid]) // If it is in right sorted part
            {
                if (nums[mid] <= target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
            {
                l++;
            }
        }

        return false;
    }
};
