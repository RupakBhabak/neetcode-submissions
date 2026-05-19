class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Setting 3 pointers
        int last = m + n - 1;
        m -= 1, n -= 1;

        // merging in reverse order
        while (n >= 0 && m >= 0) {
            if (nums1[m] > nums2[n]) {
                swap(nums1[m], nums1[last]);
                m--;
            } else {
                swap(nums1[last], nums2[n]);
                n--;
            }
            last--;
        }

        // Fill the remaining numbers of nums2
        while (n >= 0) {
            swap(nums1[last], nums2[n]);
            last--; n--;
        }
    }
};
