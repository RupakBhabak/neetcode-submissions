class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        int l = 0, r = n - 1;

        // On every step
        // One half will be sorted and another half will be unsorted

        while (l <= r)
        {
            int mid = (r - l) / 2 + l;

            if (nums[mid] == target)
                return mid;

            if (nums[l] <= nums[mid]) // If left half is sorted
            {
                if (nums[l] <= target && target <= nums[mid]) // If target lies b/w sorted half
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else                      // If right half is sorted 
            {
                if (nums[mid] <= target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return -1;
    }
};
