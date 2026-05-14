class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        if (nums.size() == 0)
            return 0;

        if (nums.size() == 1) {
            if (nums[0] == val)
                return 0;
            else
                return 1;
        }

        int i = 0, j = nums.size() - 1, k = 0;

        while (nums[j] == val && j >= 0) 
            j--;

        while (i <= j && i < nums.size() && j >= 0) {
            if (nums[i] == val) {
                swap(nums[i], nums[j]);
                
                while (nums[j] == val && j >= 0) 
                    j--;
            }

            i++;
        }

        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != val)
                k++;
            else
                break;
        }

        return k;
    }
};