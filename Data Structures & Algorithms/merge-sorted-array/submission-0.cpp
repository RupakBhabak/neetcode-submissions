class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        while (m < nums1.size() && i < nums2.size()) {
            nums1[m] = nums2[i];
            m++; i++;
        }

        sort(nums1.begin(), nums1.end());
    }
};
