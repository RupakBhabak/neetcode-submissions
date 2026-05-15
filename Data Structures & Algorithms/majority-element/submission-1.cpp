class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0], freq = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == majority) {
                freq++;
            } else {
                freq--;
            }

            if (freq == 0) {
                majority = nums[i];
                freq = 1;
            }
        }

        return majority;
    }
};