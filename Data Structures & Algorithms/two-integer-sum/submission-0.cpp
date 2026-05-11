class Solution {
   public:
    // nums[i] + nums[j] = target
    // difference = target - nums[i]
    // check if that diff(2nd number) exists before in the array or not by HashMap
    // if found, return the answer
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> M;  // Map -> (num, indx)

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (M.find(diff) != M.end()) {
                if (M[diff] != i) {
                    ans = {M[diff], i};
                    break;
                }
            } else {
                M[nums[i]] = i;
            }
        }

        return ans;
    }
};
