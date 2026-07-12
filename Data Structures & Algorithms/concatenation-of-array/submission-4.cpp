class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
    vector<int> ans(nums.size()*2, 0);
    
    for (int i = 0; i < nums.size(); i++) {
        ans[i] = nums[i];
    }

    for (int i = nums.size(); i < nums.size()*2; i++) {
        ans[i] = nums[i - nums.size()];
    }

    return ans;
} 
};