class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> M; // Map->(item, freq)

        for (int i = 0; i < nums.size(); i++) {
            if (M.find(nums[i]) != M.end()) {
                M[nums[i]]++;
            } else {
                M[nums[i]] = 1;
            }
        }

        int majority;
        for (auto elem : M) {
            if (elem.second > nums.size() / 2) {
                majority = elem.first;
                break;
            }
        }

        return majority;
    }
};