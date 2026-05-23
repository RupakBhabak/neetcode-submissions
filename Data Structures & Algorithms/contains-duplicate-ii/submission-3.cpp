class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> M; // Map -> (elem, indx)
        int i = 0, j = 0;

        while (i < nums.size() && j < nums.size()) {
            if (j - i > k) {
                M.erase(nums[i]);
                i++;
            }
            
            if (M.find(nums[j]) != M.end()) {
                return true;
            }

            M[nums[j]] = j;
            j++;
        }

        return false;
    }
};
