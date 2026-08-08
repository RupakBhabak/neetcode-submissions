class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;

        while (row < m && col >= 0)
        {
            int curr = matrix[row][col];

            if (curr == target)
                return true;

            if (target > curr)
            {
                row++;
            }
            else
            {
                col--;
            }
        }

        return false;
    }
};
