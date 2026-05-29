class Solution {
public:
    int mySqrt(int x) {
        int i = 0, j = x;
        int nearest = 0;

        while (i <= j) {
            int mid = i + (j - i)/2;

            if ((long long)mid * mid > x) {
                j = mid - 1;
            } else if ((long long)mid * mid < x) {
                i = mid + 1;
                nearest = mid;
            } else {
                return mid;
            }
        }

        return nearest;
    }
};