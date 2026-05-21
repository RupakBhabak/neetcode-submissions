class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) 
            return 1;
        
        int k = 1;
        int i = 0, j = 0;

        while (i < nums.size() && j < nums.size()) {
            if (nums[i] == nums[j]) {
                j++;
            } else {
                i++;
                swap(nums[i], nums[j]);
                j++;
                k++;
            }
        }

        return k;
    }
};
