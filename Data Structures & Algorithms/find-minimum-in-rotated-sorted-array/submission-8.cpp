class Solution {
   public:
    int findMin(vector<int>& nums) {
        const int n = nums.size();
        int l = 0, r = n - 1;
        int ans = INT_MAX;

        while (l <= r) 
        {
            // if in not rotated part
            if (nums[l] < nums[r])
            {
                ans = min(ans, nums[l]);
                break;
            }
            
            int mid = (r - l) / 2 + l;
            ans = min(ans, nums[mid]);

            // if nums[mid] >= nums[l] -> search right
            // else search left
            if (nums[mid] >= nums[l]) 
                l = mid + 1;
            else
                r = mid - 1;
        }

        return ans;
    }
};
